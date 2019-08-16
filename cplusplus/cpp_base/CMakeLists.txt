
#project(cpp_base)
set(EXCUtTE_NAME cpp_base)
add_executable(${EXCUtTE_NAME} 
                main.cpp
                main.h
                c11.cpp)
set_target_properties(${EXCUtTE_NAME} PROPERTIES FOLDER "${folder_cpp}")