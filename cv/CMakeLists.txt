set(folder_cv "cv")

# find opencv
set(OpenCV_DIR "D:\\Programs\\opencv401_debug")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(freetype)
add_subdirectory(opencv_base)