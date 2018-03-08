g++ -O3 -std=c++14 ./main.cc \
    `pkg-config --libs --cflags opencv` \
    -lX11 -lpthread  -ldlib \
    -llapack  -lblas