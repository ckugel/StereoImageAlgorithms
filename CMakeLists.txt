cmake_minimum_required(VERSION 3.24)
project(StereoAlgorithms)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include(CTest)
enable_testing()

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(StereoAlgorithms src/main.cpp src/StereoCalibration.cpp src/StereoCalibration.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

TARGET_LINK_LIBRARIES(StereoAlgorithms ${OpenCV_LIBS})
