FROM developer_shell
RUN apt install -y build-essential
RUN apt install -y cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
RUN apt install -y python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev

WORKDIR /opt
RUN wget https://github.com/opencv/opencv/archive/3.4.1.tar.gz
RUN tar -zxvf 3.4.1.tar.gz && mv opencv-3.4.1 opencv
RUN cd opencv && mkdir build 
WORKDIR /opt/opencv/build
RUN cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local ..
RUN make -j2
RUN make install

WORKDIR /opt/
RUN wget https://github.com/davisking/dlib/archive/v19.9.tar.gz
RUN tar -zxvf v19.9.tar.gz && mv dlib-19.9 dlib
RUN cd dlib && mkdir build
RUN apt install -y libopenblas-dev liblapack-dev
WORKDIR /opt/dlib/build
RUN cmake -DCMAKE_BUILD_TYPE=Release\
           -DCMAKE_INSTALL_PREFIX=/usr/local\
           -DUSE_AVX_INSTRUCTIONS=1 ..
RUN make -j2
RUN make install

RUN apt install -y qtcreator
RUN apt update && apt install -y plantuml

# RUN apt install -y libopencv-dev libdlib-dev libblas-dev liblapack-dev
CMD ["/bin/zsh"]
