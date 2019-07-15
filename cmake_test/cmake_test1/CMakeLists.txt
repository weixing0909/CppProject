# text detection

message("entry cmake test1")

macro(macro_test PARAMETER)
  message("macro test ${PARAMETER}")
  message("ARGN: ${ARGN}")
  foreach(__variableName ${ARGN})
    message("ARGN2: ${__variableName}")
  endforeach()
endmacro()
macro_test("test1" "wwww" 4)
macro_test(1 2 3)

set(EXCUtTE_NAME cmake_test1)
message(${EXCUtTE_NAME})

add_executable(${EXCUtTE_NAME} main.cpp)
set_target_properties(${EXCUtTE_NAME} PROPERTIES FOLDER "${cmake}")