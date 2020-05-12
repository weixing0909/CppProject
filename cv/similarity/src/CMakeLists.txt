# 8 ball program

message(" ${CMAKE_SOURCE_DIR}")
message(" ${CMAKE_BINARY_DIR}")
if((" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}"))
  message(FATAL_ERROR "source dir must be unequal binary dir")
endif()

cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)

add_compile_options(-std=c++11)

project(similarity) # holaverse 8 ball pool assistant

# find opencv
set(OpenCV_DIR "C:\\Programs\\opencv401_debug")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(EXCUtTE_NAME_1 similarity)
add_executable(${EXCUtTE_NAME_1} 
                main.cpp
              )
target_link_libraries(${EXCUtTE_NAME_1} ${OpenCV_LIBS})


