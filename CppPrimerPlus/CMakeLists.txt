set(folder_cpp_primer_plus "CppPrimerPlus")

set(folder_cpp_primer_plus_Chapter01 "Chapter01")
set(EXCUtTE_NAME_CHAPTER_01_1 CppPrimerPlus_C01_1)
add_executable(${EXCUtTE_NAME_CHAPTER_01} 
                Chapter01/main.cpp)
set_target_properties(${EXCUtTE_NAME_CHAPTER_01} PROPERTIES FOLDER "${folder_cpp_primer_plus}/${folder_cpp_primer_plus_Chapter01}")