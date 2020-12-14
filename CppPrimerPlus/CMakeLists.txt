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
add_executable(c4_14_address ${ChapterNumber}/c4_14_address.cpp)
add_executable(c4_15_pointer ${ChapterNumber}/c4_15_pointer.cpp)
add_executable(c4_19_addpntrs ${ChapterNumber}/c4_19_addpntrs.cpp)
set_target_properties(
    c4_11_strucrur
    c4_14_address
    c4_15_pointer
    c4_19_addpntrs
    PROPERTIES FOLDER "${folder_cpp_primer_plus}/${ChapterNumber}")

# Chapter 05
set(ChapterNumber "Chapter05")
add_executable(c5_8_block ${ChapterNumber}/c5_8_block.cpp)
add_executable(c5_19_textin4 ${ChapterNumber}/c5_19_textin4.cpp)
set_target_properties(
    c5_8_block
    c5_19_textin4
    PROPERTIES FOLDER "${folder_cpp_primer_plus}/${ChapterNumber}")

# Chapter 06
set(ChapterNumber "Chapter06")
add_executable(c6_16_outfile ${ChapterNumber}/c6_16_outfile.cpp)
set_target_properties(
    c6_16_outfile
    PROPERTIES FOLDER "${folder_cpp_primer_plus}/${ChapterNumber}")

# Chapter 07
set(ChapterNumber "Chapter07")
add_executable(c7_7_arrfun3 ${ChapterNumber}/c7_7_arrfun3.cpp)
add_executable(c7_15_arrobj ${ChapterNumber}/c7_15_arrobj.cpp)
set_target_properties(
    c7_7_arrfun3
    c7_15_arrobj
    PROPERTIES FOLDER "${folder_cpp_primer_plus}/${ChapterNumber}")

# Chapter 08
set(ChapterNumber "Chapter08")
add_executable(c8_1_inline ${ChapterNumber}/c8_1_inline.cpp)
add_executable(c8_8_filefunc ${ChapterNumber}/c8_8_filefunc.cpp)
add_executable(c8_11_functemp ${ChapterNumber}/c8_11_functemp.cpp)
add_executable(c8_t1 ${ChapterNumber}/c8_t1.cpp)
set_target_properties(
    c8_1_inline
    c8_8_filefunc
    c8_11_functemp
    c8_t1
    PROPERTIES FOLDER "${folder_cpp_primer_plus}/${ChapterNumber}")

# Chapter 10
set(ChapterNumber "Chapter10")
add_executable(c10_1_usestock0 
                ${ChapterNumber}/c10_1_usestock0.cpp 
                ${ChapterNumber}/c10_1_stock00.h
                ${ChapterNumber}/c10_1_stock00.cpp)
add_executable(c10_2_usestock2 
                ${ChapterNumber}/c10_2_usestock2.cpp 
                ${ChapterNumber}/c10_2_stock20.h
                ${ChapterNumber}/c10_2_stock20.cpp)
add_executable(c10_3_stacker
                ${ChapterNumber}/c10_3_stacker.cpp 
                ${ChapterNumber}/c10_3_stack.h
                ${ChapterNumber}/c10_3_stack.cpp)
set_target_properties(
    c10_1_usestock0
    c10_2_usestock2
    c10_3_stacker
    PROPERTIES FOLDER "${folder_cpp_primer_plus}/${ChapterNumber}")

# Chapter 11
set(ChapterNumber "Chapter11")
add_executable(c11_6_usetime1 ${ChapterNumber}/c11_6_usetime1.cpp)
add_executable(c11_15_randwalk
                ${ChapterNumber}/c11_15_randwalk.cpp 
                ${ChapterNumber}/c11_13_vector.h
                ${ChapterNumber}/c11_14_vector.cpp)
set_target_properties(
    c11_6_usetime1
    c11_15_randwalk
    PROPERTIES FOLDER "${folder_cpp_primer_plus}/${ChapterNumber}")