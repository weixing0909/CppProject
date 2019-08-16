
set(FREETYPE_ROOT "D:\\Programs\\freetype2")
include_directories(${FREETYPE_ROOT}/include)
link_libraries(${FREETYPE_ROOT}/x86/vc15/lib/freetype.lib)

set(EXCUtTE_NAME freetype_test)
add_executable(${EXCUtTE_NAME} 
            main.cpp 
            main.h  )
target_link_libraries(${EXCUtTE_NAME} ${OpenCV_LIBS})
target_link_libraries(${EXCUtTE_NAME} ${FREETYPE_ROOT}/x86/vc15/lib/freetype.lib)
set_target_properties(${EXCUtTE_NAME} PROPERTIES FOLDER "${folder_cv}")