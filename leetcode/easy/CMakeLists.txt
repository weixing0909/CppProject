set(folder_easy "easy")

add_executable(q70_ClimbingStairs q70_ClimbingStairs.cpp)
set_target_properties(q70_ClimbingStairs PROPERTIES FOLDER "${folder_leetcode}/${folder_easy}")

add_executable(q112_PathSum q112_PathSum.cpp)
set_target_properties(q112_PathSum PROPERTIES FOLDER "${folder_leetcode}/${folder_easy}")
