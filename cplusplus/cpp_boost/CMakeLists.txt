
set(EXCUtTE_NAME cpp_boost)

SET (BOOST_ROOT "D:\\Programs\\boost_1_69_0_x86")
SET (BOOST_MIN_VERSION "1.62.0")
FIND_PACKAGE(Boost ${BOOST_MIN_VERSION} COMPONENTS filesystem regex REQUIRED)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Fatal error: Boost (version >= ${BOOST_MIN_VERSION}) required.")
endif(NOT Boost_FOUND)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_executable(${EXCUtTE_NAME} 
                main.cpp
                main.h
                boost_filesystem_test.cpp)


target_link_libraries(${EXCUtTE_NAME} ${Boost_LIBRARIES})
set_target_properties(${EXCUtTE_NAME} PROPERTIES FOLDER "${folder_cpp}")