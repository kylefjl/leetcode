cmake_minimum_required(VERSION 3.22)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(P1_TwoSum
        "editor/cn/P1_TwoSum.cpp")

add_executable(P2_AddTwoNumbers  "editor/cn/P2_AddTwoNumbers.cpp")
add_executable(P5_LongestPalindromicSubstring editor/cn/P5_LongestPalindromicSubstring.cpp)
add_executable(P15_ThreeSum editor/cn/P15_ThreeSum.cpp)
add_executable(P20_ValidParentheses editor/cn/P20_ValidParentheses.cpp)
add_executable(P21_MergeTwoSortedLists editor/cn/P21_MergeTwoSortedLists.cpp)
add_executable(P23_MergeKSortedLists editor/cn/P23_MergeKSortedLists.cpp)
add_executable(P24_SwapNodesInPairs editor/cn/P24_SwapNodesInPairs.cpp)
add_executable(P25_ReverseNodesInKGroup editor/cn/P25_ReverseNodesInKGroup.cpp)


add_executable(P36_ValidSudoku editor/cn/P36_ValidSudoku.cpp)

add_executable(P42_TrappingRainWater editor/cn/P42_TrappingRainWater.cpp)

add_executable(P43_MultiplyStrings editor/cn/P43_MultiplyStrings.cpp)
