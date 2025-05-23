CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

set(ENABLE_ONNXRUNTIME ON)
set(ENABLE_MNN OFF)
set(ENABLE_NCNN OFF)
set(ENABLE_TNN OFF)
set(ENABLE_TENSORRT OFF)
set(CUDA_DIR )
set(TensorRT_DIR )

# system and backend check
if (NOT (UNIX AND NOT APPLE))
  message(FATAL_ERROR "lite.ai.toolkit>=0.2 not support for windows/mac now!")
endif()

if ((NOT ENABLE_ONNXRUNTIME) AND (NOT ENABLE_MNN))
    message(FATAL_ERROR "One of ONNXRuntime/MNN Backend must be enable!")
endif()

# lite.ai.toolkit 
set(LITE_AI_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(THIRD_PARTY_PATH ${CMAKE_CURRENT_LIST_DIR}/third_party)
set(LITE_AI_LIB_DIR ${CMAKE_CURRENT_LIST_DIR}/lib)

set(Lite_AI_INCLUDE_DIRS ${LITE_AI_INCLUDE_DIR})
set(Lite_AI_LIBS_DIRS ${LITE_AI_LIB_DIR})
set(Lite_AI_LIBS lite.ai.toolkit)

include_directories(${LITE_AI_INCLUDE_DIR})
link_directories(${LITE_AI_LIB_DIR})

# opencv
include_directories(${THIRD_PARTY_PATH}/opencv/include/opencv4)
link_directories(${THIRD_PARTY_PATH}/opencv/lib)
list(APPEND Lite_AI_INCLUDE_DIRS ${THIRD_PARTY_PATH}/opencv/include/opencv4)
list(APPEND Lite_AI_LIBS_DIRS ${THIRD_PARTY_PATH}/opencv/lib)
set(OpenCV_LIBS opencv_core opencv_imgcodecs opencv_imgproc opencv_video opencv_videoio) # linux only
list(APPEND Lite_AI_LIBS ${OpenCV_LIBS})

# onnxruntime
if (ENABLE_ONNXRUNTIME)
  include_directories(${THIRD_PARTY_PATH}/onnxruntime/include)
  link_directories(${THIRD_PARTY_PATH}/onnxruntime/lib)
  list(APPEND Lite_AI_INCLUDE_DIRS ${THIRD_PARTY_PATH}/onnxruntime/include)
  list(APPEND Lite_AI_LIBS_DIRS ${THIRD_PARTY_PATH}/onnxruntime/lib)
  list(APPEND Lite_AI_LIBS onnxruntime)
endif()

# MNN
if (ENABLE_MNN)
  include_directories(${THIRD_PARTY_PATH}/MNN/include)
  link_directories(${THIRD_PARTY_PATH}/MNN/lib)
  list(APPEND Lite_AI_INCLUDE_DIRS ${THIRD_PARTY_PATH}/MNN/include)
  list(APPEND Lite_AI_LIBS_DIRS ${THIRD_PARTY_PATH}/MNN/lib)
  list(APPEND Lite_AI_LIBS MNN)
endif()

# TNN
if (ENABLE_TNN)
  include_directories(${THIRD_PARTY_PATH}/TNN/include)
  link_directories(${THIRD_PARTY_PATH}/TNN/lib)
  list(APPEND Lite_AI_INCLUDE_DIRS ${THIRD_PARTY_PATH}/TNN/include)
  list(APPEND Lite_AI_LIBS_DIRS ${THIRD_PARTY_PATH}/TNN/lib)
  list(APPEND Lite_AI_LIBS TNN)
endif()

# ncnn
if (ENABLE_NCNN)
  include_directories(${THIRD_PARTY_PATH}/ncnn/include)
  link_directories(${THIRD_PARTY_PATH}/ncnn/lib)
  list(APPEND Lite_AI_INCLUDE_DIRS ${THIRD_PARTY_PATH}/ncnn/include)
  list(APPEND Lite_AI_LIBS_DIRS ${THIRD_PARTY_PATH}/ncnn/lib)
  list(APPEND Lite_AI_LIBS ncnn)
endif()

# tensorrt
if (ENABLE_TENSORRT)
  include_directories(${TensorRT_DIR}/include)
  include_directories(${CUDA_DIR}/include)
  link_directories(${CUDA_DIR}/lib64)
  link_directories(${TensorRT_DIR}/lib)
  list(APPEND Lite_AI_INCLUDE_DIRS ${TensorRT_DIR}/include)
  list(APPEND Lite_AI_LIBS_DIRS ${TensorRT_DIR}/lib)
  list(APPEND Lite_AI_LIBS cuda nvinfer nvonnxparser nvinfer_plugin)
endif()
