from computer_vision_environment
RUN git clone https://github.com/alexkutsan/FaceLocker 
WORKDIR FaceLocker
RUN git checkout face_recognize
RUN mkdir build
WORKDIR build
RUN cmake  -DCMAKE_BUILD_TYPE=Release ..
RUN make -j4
RUN chmod a+rw /dev/video0
CMD ["./video_test"]
