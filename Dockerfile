from computer_vision_environment
RUN git clone https://github.com/alexkutsan/FaceLocker 
WORKDIR FaceLocker
RUN git checkout face_recognize
RUN mkdir build
WORKDIR build
RUN cmake  -DCMAKE_BUILD_TYPE=Release ..
RUN make -j4
ADD entrypoint.sh /usr/bin/video_entry_point.sh
ENTRYPOINT ["/bin/bash", "-e", "/usr/bin/video_entry_point.sh"]
CMD ["./video_test"]
