#include <algorithm>
#include <iostream>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/video/tracking.hpp>
#include "opencv2/features2d/features2d.hpp"

#include "optical_flow_detector_impl.h"
namespace training {

OpticalFlowDetectorImpl::OpticalFlowDetectorImpl()
    : threashold_func_([](const float mean_error,
                          const float stddev_error) -> FilterFunction {
      return [=](const TackedPoint& point) -> bool {
        return point.is_tracked &&
               std::abs(point.error - mean_error) < stddev_error * 3;
      };
    })
    , tracked_frame_callback_([](cv::Mat frame, cv::Rect object_frame) {}) {}

void OpticalFlowDetectorImpl::ProcessFrame(const cv::Mat& frame) {
  std::vector<cv::Point2f> tracked_points;
  std::vector<uchar> tracked_points_status;
  cv::Mat errors;
  cv::Mat grey;
  cv::cvtColor(frame, grey, CV_BGR2GRAY);
  cv::calcOpticalFlowPyrLK(last_frame_,
                           grey,
                           last_good_key_points_,
                           tracked_points,
                           tracked_points_status,
                           errors);

  const std::vector<cv::Point2f> new_points = GetNewPoints(
      last_good_key_points_, tracked_points, tracked_points_status, errors);
  cv::Rect object_rect = RectByPoints(new_points);
  if (object_rect.area() > 0) {
    last_good_key_points_ = new_points;
    last_frame_ = grey;
    tracked_frame_callback_(frame, object_rect);
    cv::Mat to_draw = last_frame_.clone();
    for (auto p : last_good_key_points_) {
      cv::circle(to_draw, p, 10, cv::Scalar(255, 0, 0));
    }
    cv::rectangle(to_draw, object_rect, cv::Scalar(255, 0, 0));
    cv::imshow("MainWindow", to_draw);
  }
}

void OpticalFlowDetectorImpl::InitTracking(
    cv::Mat frame, std::vector<cv::Point2f>& points_to_track) {
  std::swap(last_good_key_points_, points_to_track);
  cv::cvtColor(frame, last_frame_, CV_BGR2GRAY);
}

std::function<bool(const TackedPoint& point)>
OpticalFlowDetectorImpl::GetExtractTrackedFilter(
    std::vector<TackedPoint> tracked) {
  const size_t count_tracked =
      std::count_if(tracked.begin(),
                    tracked.end(),
                    [](const TackedPoint& t) { return t.is_tracked; });
  std::function<float(float, const TackedPoint& t)> accumulator_filter =
      [=](float initial, const TackedPoint& t)
          -> float { return t.is_tracked ? initial + t.error : initial; };

  std::function<float((const TackedPoint& t1, const TackedPoint& t2))> product =
      [](const TackedPoint& t1, const TackedPoint& t2)
          -> float { return t1.error * t2.error; };

  const float error_sum =
      std::accumulate(tracked.begin(), tracked.end(), 0.0, accumulator_filter);
  const float mean = error_sum / count_tracked;
  const float sq_sum = std::inner_product(tracked.begin(),
                                          tracked.end(),
                                          tracked.begin(),
                                          0.0,
                                          std::plus<float>(),
                                          product);
  const float stdev = std::sqrt(sq_sum / count_tracked - mean * mean);

  return threashold_func_(mean, stdev);
}

cv::Rect OpticalFlowDetectorImpl::RectByPoints(
    std::vector<cv::Point2f> points) {
  if (points.size() < 4) {
    return cv::Rect(0, 0, 0, 0);
  }
  cv::Point2f top_left = points.front();
  cv::Point2f buttom_right = points.front();
  for (auto point : points) {
    top_left.x = point.x < top_left.x ? point.x : top_left.x;
    top_left.y = point.y < top_left.y ? point.y : top_left.y;
    buttom_right.x = point.x > buttom_right.x ? point.x : buttom_right.x;
    buttom_right.y = point.y > buttom_right.y ? point.y : buttom_right.y;
  }
  cv::Rect points_rect(top_left, buttom_right);
  return points_rect;
}

const std::vector<cv::Point2f> OpticalFlowDetectorImpl::GetNewPoints(
    const std::vector<cv::Point2f>& previous_points,
    const std::vector<cv::Point2f>& next_points,
    const std::vector<uchar>& tracked_status,
    const cv::Mat& errors) {
  std::vector<TackedPoint> tracked;
  for (size_t i = 0; i < tracked_status.size(); ++i) {
    TackedPoint t = {previous_points[i],
                     next_points[i],
                     static_cast<bool>(tracked_status[i]),
                     errors.at<float>(i)};
    tracked.push_back(t);
  }
  auto tracked_filter = GetExtractTrackedFilter(tracked);
  std::vector<cv::Point2f> result;
  for (auto it = tracked.begin(); it != tracked.end(); ++it) {
    if (tracked_filter(*it)) {
      result.push_back(it->next);
    }
  }
  return FilterVeryFarPoints(result);
}

std::vector<cv::Point2f> OpticalFlowDetectorImpl::FilterVeryFarPoints(
    const std::vector<cv::Point2f>& points) {
  cv::Point2f midle;
  midle.x = std::accumulate(
                points.begin(),
                points.end(),
                0.0,
                [&](double sum, cv::Point2f point) { return sum + point.x; }) /
            points.size();
  midle.y = std::accumulate(
                points.begin(),
                points.end(),
                0.0,
                [&](double sum, cv::Point2f point) { return sum + point.y; }) /
            points.size();

  auto calc_distance = [](cv::Point2f p1, cv::Point2f p2) -> double {
    double kat1 = std::max(p1.x, p2.x) - std::min(p1.x, p2.x);
    double kat2 = std::max(p1.y, p2.y) - std::min(p1.y, p2.y);
    return sqrt(kat1 * kat1 + kat2 * kat2);
  };

  double mid_distance =
      std::accumulate(points.begin(),
                      points.end(),
                      0.0,
                      [&](double sum, cv::Point2f point) {
                        return sum + calc_distance(midle, point);
                      }) /
      points.size();
  auto product_distance = [&](cv::Point2f p1, cv::Point2f p2) {
    return calc_distance(p1, midle) * calc_distance(p2, midle);
  };

  const double sq_sum = std::inner_product(points.begin(),
                                           points.end(),
                                           points.begin(),
                                           0.0,
                                           std::plus<double>(),
                                           product_distance);

  const double stdev =
      std::sqrt(sq_sum / points.size() - mid_distance * mid_distance);

  std::vector<cv::Point2f> filtered;
  for (cv::Point2f p : points) {
    const double dist = calc_distance(p, midle);
    if (dist < 5 * stdev) {
      filtered.push_back(p);
    }
  }
  return filtered;
}

void OpticalFlowDetectorImpl::set_on_object_tracked(TrackedFrameCallback func) {
  tracked_frame_callback_ = func;
}

ThreasholdFunction OpticalFlowDetectorImpl::threashold_func() const {
  return threashold_func_;
}

void OpticalFlowDetectorImpl::set_threashold_func(
    const ThreasholdFunction& threashold_func) {
  threashold_func_ = threashold_func;
}
}
