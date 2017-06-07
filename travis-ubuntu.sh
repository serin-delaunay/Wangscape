pwd
mkdir build
docker run -v $(pwd):/Wangscape lukequaint/wangscape-build:latest /bin/sh -c \
'cd /Wangscape/build && cmake .. && make;
 Xvfb :1 -screen 0 1600x900x24 &> xvfb.log &
 DISPLAY=:1.0; export DISPLAY;
 xvfb-run --server-args "-screen 0 1600x900x24" ./bin/WangscapeTest ../doc'
