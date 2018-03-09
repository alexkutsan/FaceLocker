
docker run -it --rm --device /dev/video0  \
	   -e LINES=$(tput lines) -e COLUMNS=$(tput cols) \
           -e LOCAL_USER_ID=`id -u $USER` -e DISPLAY=$DISPLAY \
           --security-opt seccomp=unconfined \
           -v /tmp/.X11-unix:/tmp/.X11-unix -v ~/fun:/home/developer/fun \
           developer_fun
