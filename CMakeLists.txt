# cmake test

message(" ${CMAKE_SOURCE_DIR}")
message(" ${CMAKE_BINARY_DIR}")
if((" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}"))
  message(FATAL_ERROR "CMAKE_SOURCE_DIR EQUAL CMAKE_BINARY_DIR")
endif()

cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)

# used to organize targets in IDE
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")

add_compile_options(-std=c++11)

project(cpp_prj)

set(CMAKE_CXX_STANDARD 11)

#add_subdirectory(algorithm)
#add_subdirectory(cmake_test)
add_subdirectory(cpp_base)
add_subdirectory(CppPrimerPlus)
#add_subdirectory(cplusplus)
#add_subdirectory(cv)
#add_subdirectory(SDL_test)
add_subdirectory(sword_to_offer)
