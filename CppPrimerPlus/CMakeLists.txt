set(folder_cpp_primer_plus "CppPrimerPlus")

# Chapter 01
set(ChapterNumber "Chapter01")
add_executable(c1_1_myfirst ${ChapterNumber}/main.cpp)
set_target_properties(
    c1_1_myfirst
    PROPERTIES FOLDER "${folder_cpp_primer_plus}/${ChapterNumber}")


# Chapter 02
set(ChapterNumber "Chapter02")
add_executable(c2_1_myfirst ${ChapterNumber}/c2_1_myfirst.cpp)
add_executable(c2_2_carrot  ${ChapterNumber}/c2_2_carrot.cpp)
add_executable(c2_3_getinfo ${ChapterNumber}/c2_3_getinfo.cpp)
add_executable(c2_4_sqrt    ${ChapterNumber}/c2_4_sqrt.cpp)
add_executable(c2_5_ourfunc ${ChapterNumber}/c2_5_ourfunc.cpp)
add_executable(c2_6_convert ${ChapterNumber}/c2_6_convert.cpp)
set_target_properties(
    c2_1_myfirst
    c2_2_carrot 
    c2_3_getinfo
    c2_4_sqrt   
    c2_5_ourfunc
    c2_6_convert 
    PROPERTIES FOLDER "${folder_cpp_primer_plus}/${ChapterNumber}")


# Chapter 03
set(ChapterNumber "Chapter03")
add_executable(c3_1_limits ${ChapterNumber}/c3_1_limits.cpp)
add_executable(c3_2_exceed ${ChapterNumber}/c3_2_exceed.cpp)
add_executable(c3_3_hexoct1 ${ChapterNumber}/c3_3_hexoct1.cpp)
add_executable(c3_4_hexoct2 ${ChapterNumber}/c3_4_hexoct2.cpp)
add_executable(c3_8_floatnum ${ChapterNumber}/c3_8_floatnum.cpp)
set_target_properties(
    c3_1_limits
    c3_2_exceed
    c3_3_hexoct1
    c3_4_hexoct2
    c3_8_floatnum
    PROPERTIES FOLDER "${folder_cpp_primer_plus}/${ChapterNumber}")

# Chapter 04
set(ChapterNumber "Chapter04")
add_executable(c4_11_strucrur ${ChapterNumber}/c4_11_strucrur.cpp)
set_target_properties(
    c4_11_strucrur
    PROPERTIES FOLDER "${folder_cpp_primer_plus}/${ChapterNumber}")