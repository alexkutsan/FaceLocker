g++ -O2 -std=c++11 ./main.cc \
    `pkg-config --libs --cflags opencv` \
    -lX11 -lpthread  -ldlib \
    -llapack  -lblas