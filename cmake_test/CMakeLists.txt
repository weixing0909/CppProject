
include(cmakes/Config.cmake)
message("CMAKE_GENERATOR: " ${CMAKE_GENERATOR})
message("CMAKE_SYSTEM_NAME: " ${CMAKE_SYSTEM_NAME})
message("CMAKE_HOST_SYSTEM_NAME: " ${CMAKE_HOST_SYSTEM_NAME})
message("MIN_VER_CMAKE: " ${MIN_VER_CMAKE})


set(folder_cmake "cmake")
add_subdirectory(cmake_test1)