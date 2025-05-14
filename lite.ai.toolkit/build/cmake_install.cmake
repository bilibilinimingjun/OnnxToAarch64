# Install script for directory: /home/user/library/lite.ai.toolkit

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/user/library/lite.ai.toolkit/build/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "MinSizeRel")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblite.ai.toolkit.so.0.3.1" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblite.ai.toolkit.so.0.3.1")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblite.ai.toolkit.so.0.3.1"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/user/library/lite.ai.toolkit/build/liblite.ai.toolkit.so.0.3.1")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblite.ai.toolkit.so.0.3.1" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblite.ai.toolkit.so.0.3.1")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblite.ai.toolkit.so.0.3.1"
         OLD_RPATH "/home/user/library/lite.ai.toolkit/third_party/onnxruntime/lib:/home/user/library/lite.ai.toolkit/lite/bin:/home/user/library/opencv-4.5.2/build/your-path-to-custom-dir/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblite.ai.toolkit.so.0.3.1")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/user/library/lite.ai.toolkit/build/liblite.ai.toolkit.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/user/library/lite.ai.toolkit/build/install/include/lite")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/user/library/lite.ai.toolkit/build/install/include" TYPE DIRECTORY FILES "/home/user/library/lite.ai.toolkit/lite" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/user/library/lite.ai.toolkit/build/install/third_party")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/user/library/lite.ai.toolkit/build/install" TYPE DIRECTORY FILES "/home/user/library/lite.ai.toolkit/third_party")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/user/library/lite.ai.toolkit/build/install/lite.ai.toolkit.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/user/library/lite.ai.toolkit/build/install" TYPE FILE FILES "/home/user/library/lite.ai.toolkit/cmake/lite.ai.toolkit.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/user/library/lite.ai.toolkit/build/install/lite.ai.toolkit-config.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/user/library/lite.ai.toolkit/build/install" TYPE FILE FILES "/home/user/library/lite.ai.toolkit/cmake/lite.ai.toolkit-config.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/user/library/lite.ai.toolkit/build/install/bin/libonnxruntime.so;/home/user/library/lite.ai.toolkit/build/install/bin/libonnxruntime.so.1.17.1;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_calib3d.so;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_calib3d.so.4.5;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_calib3d.so.4.5.2;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_core.so;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_core.so.4.5;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_core.so.4.5.2;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_dnn.so;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_dnn.so.4.5;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_dnn.so.4.5.2;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_features2d.so;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_features2d.so.4.5;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_features2d.so.4.5.2;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_flann.so;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_flann.so.4.5;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_flann.so.4.5.2;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_gapi.so;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_gapi.so.4.5;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_gapi.so.4.5.2;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_highgui.so;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_highgui.so.4.5;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_highgui.so.4.5.2;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_imgcodecs.so;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_imgcodecs.so.4.5;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_imgcodecs.so.4.5.2;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_imgproc.so;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_imgproc.so.4.5;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_imgproc.so.4.5.2;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_ml.so;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_ml.so.4.5;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_ml.so.4.5.2;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_objdetect.so;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_objdetect.so.4.5;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_objdetect.so.4.5.2;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_photo.so;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_photo.so.4.5;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_photo.so.4.5.2;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_stitching.so;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_stitching.so.4.5;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_stitching.so.4.5.2;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_video.so;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_video.so.4.5;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_video.so.4.5.2;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_videoio.so;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_videoio.so.4.5;/home/user/library/lite.ai.toolkit/build/install/bin/libopencv_videoio.so.4.5.2;/home/user/library/lite.ai.toolkit/build/install/bin/libddim_scheduler_cpp.so;/home/user/library/lite.ai.toolkit/build/install/bin/libddim_scheduler_cpp.so;/home/user/library/lite.ai.toolkit/build/install/bin/libonnxruntime.so;/home/user/library/lite.ai.toolkit/build/install/bin/libonnxruntime.so.1.17.1")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/user/library/lite.ai.toolkit/build/install/bin" TYPE FILE FILES
    "/home/user/library/lite.ai.toolkit/lib/linux/libonnxruntime.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libonnxruntime.so.1.17.1"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_calib3d.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_calib3d.so.4.5"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_calib3d.so.4.5.2"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_core.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_core.so.4.5"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_core.so.4.5.2"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_dnn.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_dnn.so.4.5"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_dnn.so.4.5.2"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_features2d.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_features2d.so.4.5"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_features2d.so.4.5.2"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_flann.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_flann.so.4.5"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_flann.so.4.5.2"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_gapi.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_gapi.so.4.5"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_gapi.so.4.5.2"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_highgui.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_highgui.so.4.5"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_highgui.so.4.5.2"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_imgcodecs.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_imgcodecs.so.4.5"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_imgcodecs.so.4.5.2"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_imgproc.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_imgproc.so.4.5"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_imgproc.so.4.5.2"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_ml.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_ml.so.4.5"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_ml.so.4.5.2"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_objdetect.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_objdetect.so.4.5"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_objdetect.so.4.5.2"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_photo.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_photo.so.4.5"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_photo.so.4.5.2"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_stitching.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_stitching.so.4.5"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_stitching.so.4.5.2"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_video.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_video.so.4.5"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_video.so.4.5.2"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_videoio.so"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_videoio.so.4.5"
    "/home/user/library/lite.ai.toolkit/lib/linux/libopencv_videoio.so.4.5.2"
    "/home/user/library/lite.ai.toolkit/lite/bin/ddim_scheduler_cpp-main/build/libddim_scheduler_cpp.so"
    "/home/user/library/lite.ai.toolkit/lite/bin/libddim_scheduler_cpp.so"
    "/home/user/library/lite.ai.toolkit/third_party/onnxruntime/lib/libonnxruntime.so"
    "/home/user/library/lite.ai.toolkit/third_party/onnxruntime/lib/libonnxruntime.so.1.17.1"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/user/library/lite.ai.toolkit/build/examples/lite/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/user/library/lite.ai.toolkit/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
