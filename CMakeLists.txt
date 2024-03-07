cmake_minimum_required(VERSION 3.22)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)

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

add_executable(P44_WildcardMatching editor/cn/P44_WildcardMatching.cpp)

add_executable(P48_RotateImage editor/cn/P48_RotateImage.cpp)

add_executable(P94_BinaryTreeInorderTraversal editor/cn/P94_BinaryTreeInorderTraversal.cpp)

add_executable(P98_ValidateBinarySearchTree editor/cn/P98_ValidateBinarySearchTree.cpp)

add_executable(P102_BinaryTreeLevelOrderTraversal editor/cn/P102_BinaryTreeLevelOrderTraversal.cpp)

add_executable(P1557_MinimumNumberOfVerticesToReachAllNodes editor/cn/P1557_MinimumNumberOfVerticesToReachAllNodes.cpp)

add_executable(P1971_FindIfPathExistsInGraph editor/cn/P1971_FindIfPathExistsInGraph.cpp)

add_executable(P547_NumberOfProvinces editor/cn/P547_NumberOfProvinces.cpp)

add_executable(P684_RedundantConnection editor/cn/P684_RedundantConnection.cpp)

add_executable(P685_RedundantConnectionIi editor/cn/P685_RedundantConnectionIi.cpp)

add_executable(P1584_MinCostToConnectAllPoints editor/cn/P1584_MinCostToConnectAllPoints.cpp)

add_executable(P743_NetworkDelayTime editor/cn/P743_NetworkDelayTime.cpp)

add_executable(P701_InsertIntoABinarySearchTree editor/cn/P701_InsertIntoABinarySearchTree.cpp)

add_executable(P110_BalancedBinaryTree editor/cn/P110_BalancedBinaryTree.cpp)

add_executable(P912_SortAnArray editor/cn/P912_SortAnArray.cpp)

add_executable(P85_MaximalRectangle editor/cn/P85_MaximalRectangle.cpp)

add_executable(P84_LargestRectangleInHistogram editor/cn/P84_LargestRectangleInHistogram.cpp)

add_executable(P338_CountingBits editor/cn/P338_CountingBits.cpp)

add_executable(P162_FindPeakElement editor/cn/P162_FindPeakElement.cpp)

add_executable(P46_Permutations editor/cn/P46_Permutations.cpp)

add_executable(P47_PermutationsIi editor/cn/P47_PermutationsIi.cpp)

add_executable(P51_NQueens editor/cn/P51_NQueens.cpp)

add_executable(P55_JumpGame editor/cn/P55_JumpGame.cpp)

add_executable(P62_UniquePaths editor/cn/P62_UniquePaths.cpp)

add_executable(P63_UniquePathsIi editor/cn/P63_UniquePathsIi.cpp)

add_executable(P69_Sqrtx editor/cn/P69_Sqrtx.cpp)

add_executable(P50_PowxN editor/cn/P50_PowxN.cpp)

add_executable(P61_RotateList editor/cn/P61_RotateList.cpp)

add_executable(P149_MaxPointsOnALine editor/cn/P149_MaxPointsOnALine.cpp)

add_executable(JuZhenZhongDeLuJingLcof editor/cn/JuZhenZhongDeLuJingLcof.cpp)

add_executable(P380_InsertDeleteGetrandomO1 editor/cn/P380_InsertDeleteGetrandomO1.cpp)

add_executable(P118_PascalsTriangle editor/cn/P118_PascalsTriangle.cpp)

add_executable(P121_BestTimeToBuyAndSellStock editor/cn/P121_BestTimeToBuyAndSellStock.cpp)

add_executable(P75_SortColors editor/cn/P75_SortColors.cpp)

add_executable(P1847_ClosestRoom editor/cn/P1847_ClosestRoom.cpp)

add_executable(P239_SlidingWindowMaximum editor/cn/P239_SlidingWindowMaximum.cpp)

add_executable(PQIsx9U editor/cn/PQIsx9U.cpp)

add_executable(P480_SlidingWindowMedian editor/cn/P480_SlidingWindowMedian.cpp)

add_executable(P295_FindMedianFromDataStream editor/cn/P295_FindMedianFromDataStream.cpp)

add_executable(P661_ImageSmoother editor/cn/P661_ImageSmoother.cpp)

add_executable(P478_GenerateRandomPointInACircle editor/cn/P478_GenerateRandomPointInACircle.cpp)

add_executable(P2249_CountLatticePointsInsideACircle editor/cn/P2249_CountLatticePointsInsideACircle.cpp)

add_executable(P1515_BestPositionForAServiceCentre editor/cn/P1515_BestPositionForAServiceCentre.cpp)

add_executable(P1114_PrintInOrder editor/cn/P1114_PrintInOrder.cpp)

target_link_libraries(P1114_PrintInOrder pthread)

add_executable(P1115_PrintFoobarAlternately editor/cn/P1115_PrintFoobarAlternately.cpp)

add_executable(P587_ErectTheFence editor/cn/P587_ErectTheFence.cpp)

add_executable(P200_NumberOfIslands editor/cn/P200_NumberOfIslands.cpp)

add_executable(P1093_StatisticsFromALargeSample editor/cn/P1093_StatisticsFromALargeSample.cpp)

add_executable(P704_BinarySearch editor/cn/P704_BinarySearch.cpp)

add_executable(P27_RemoveElement editor/cn/P27_RemoveElement.cpp)

add_executable(P977_SquaresOfASortedArray editor/cn/P977_SquaresOfASortedArray.cpp)

add_executable(P209_MinimumSizeSubarraySum editor/cn/P209_MinimumSizeSubarraySum.cpp)

add_executable(P59_SpiralMatrixIi editor/cn/P59_SpiralMatrixIi.cpp)

add_executable(P203_RemoveLinkedListElements editor/cn/P203_RemoveLinkedListElements.cpp)

add_executable(P707_DesignLinkedList editor/cn/P707_DesignLinkedList.cpp)

add_executable(P206_ReverseLinkedList editor/cn/P206_ReverseLinkedList.cpp)

add_executable(P19_RemoveNthNodeFromEndOfList editor/cn/P19_RemoveNthNodeFromEndOfList.cpp)

add_executable(P160_IntersectionOfTwoLinkedLists editor/cn/P160_IntersectionOfTwoLinkedLists.cpp)

add_executable(P142_LinkedListCycleIi editor/cn/P142_LinkedListCycleIi.cpp)

add_executable(P242_ValidAnagram editor/cn/P242_ValidAnagram.cpp)

add_executable(P202_HappyNumber editor/cn/P202_HappyNumber.cpp)

add_executable(P454_FourSumIi editor/cn/P454_FourSumIi.cpp)

add_executable(P18_FourSum editor/cn/P18_FourSum.cpp)

add_executable(P151_ReverseWordsInAString editor/cn/P151_ReverseWordsInAString.cpp)

add_executable(P28_FindTheIndexOfTheFirstOccurrenceInAString editor/cn/P28_FindTheIndexOfTheFirstOccurrenceInAString.cpp)

add_executable(P459_RepeatedSubstringPattern editor/cn/P459_RepeatedSubstringPattern.cpp)