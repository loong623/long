# 这是一个 CMakeLists.txt 文件
cmake_minimum_required(VERSION 3.0)
project(CALC)
#include_directories(${EIGEN_INCLUDE_DIRS})
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
add_executable(HW2 hw2.cpp)
target_link_libraries(HW2 ${OpenCV_LIBS})
target_link_libraries(HW2 ${Eigen3_LIBS})