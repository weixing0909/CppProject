
set(EXCUtTE_NAME opencv_base)
add_executable(${EXCUtTE_NAME} 
            main.cpp 
            main.h 
            opencv_01_base.cpp 
            opencv_02_data_type.cpp
            opencv_03_array_operations.cpp
            opencv_04_drawing.cpp
            opencv_05_functors.cpp
            opencv_06_filters.cpp
            opencv_07_transforms.cpp
            opencv_08_image_analysis.cpp )
target_link_libraries(${EXCUtTE_NAME} ${OpenCV_LIBS})
set_target_properties(${EXCUtTE_NAME} PROPERTIES FOLDER "${folder_cv}")