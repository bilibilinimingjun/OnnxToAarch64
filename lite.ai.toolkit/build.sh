#!/bin/bash

BUILD_DIR=build

if [ ! -d "${BUILD_DIR}" ]; then
  mkdir "${BUILD_DIR}"
  echo "creating build dir: ${BUILD_DIR} ..."
else
  echo "build dir: ${BUILD_DIR} directory exist! ..."
fi

cd "${BUILD_DIR}" && pwd 
if [ $1 == "tensorrt" ]; then
  cmake .. -DCMAKE_BUILD_TYPE=MinSizeRel \
           -DCMAKE_INSTALL_PREFIX=./install \
           -DENABLE_TENSORRT=ON \
           -DCUDA_DIR=/usr/local/cuda \
           -DTensorRT_DIR=/usr/local/tensorrt \
           -DENABLE_TEST=ON \
	       -DOpenCV_DIR=/usr/local/lib/cmake/opencv4

else
  cmake .. -DCMAKE_BUILD_TYPE=MinSizeRel \
           -DCMAKE_INSTALL_PREFIX=./install \
           -DENABLE_TEST=ON \
           -DENABLE_TENSORRT=OFF \
	       -DOpenCV_DIR=/usr/local/lib/cmake/opencv4
fi

make -j4
make install

# bash ./build.sh
# bash ./build.sh tensorrt
