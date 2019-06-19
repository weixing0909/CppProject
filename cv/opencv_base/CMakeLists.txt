
set(EXCUtTE_NAME opencv_base)
add_executable(${EXCUtTE_NAME} 
            main.cpp 
            main.h 
            opencv_01_base.cpp 
            opencv_02_data_type.cpp
            opencv_03_array_operations.cpp )
target_link_libraries(${EXCUtTE_NAME} ${OpenCV_LIBS})
set_target_properties(${EXCUtTE_NAME} PROPERTIES FOLDER "${folder_cv}")