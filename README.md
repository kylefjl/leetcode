# Leetcode 
中文版leetcode刷题仓库，主要用来记录分享自己的刷题过程

## 环境
- **语言**： c++  

- **ide**：clion 

- 为便于刷题，安装了leetcode刷题插件，所以本仓库的所有cpp文件都是基于leetcode插件模板的， [配置方法](https://blog.csdn.net/weixin_42238350/article/details/119878011)

    - 文件名模板`P$!{question.frontendQuestionId}_$!velocityTool.camelCaseName(${question.titleSlug})`

    - 文件模板

        >```c++
        >${question.content}
        >\#include<bits/stdc++.h>
        >using namespace std;
        >
        >/*
        > * ${question.title}
        > * @author name
        > * @date $!velocityTool.date()
        > */
        >${question.code}
        >
        >int main()
        >{
        >    Solution s;
        >}
        >```

## 分支说明
 - main:每道题提交的时候都是在leetcode上测试过的，有对应的笔记和完整的注释
 - dev:主要用来实现多主机上的代码同步，所以有些提交可能出现一些未完成的代码
>[交流｜科普一下力扣的运行时间，以及beats 100%的那些事 - 力扣（LeetCode）](https://leetcode.cn/circle/discuss/cErV2N/)

## 题

1. 两数之和
   - [题目](editor/cn/doc/content/P1_TwoSum.md)  [程序](editor/cn/P1_TwoSum.cpp) [笔记](editor/cn/doc/note/P1_TwoSum.md)
   
     >执行耗时:8 ms,击败了91.36% 的C++用户
     >内存消耗:10.2 MB,击败了53.73% 的C++用户
   
2. 两数相加
   - [题目](editor/cn/doc/content/P2_AddTwoNumbers.md)  [程序](editor/cn/P2_AddTwoNumbers.cpp) [笔记](editor/cn/doc/note/P2_AddTwoNumbers.md)
   
     >执行耗时:24 ms,击败了76.79% 的C++用户
     >内存消耗:69.3 MB,击败了88.88% 的C++用户
   
3. 最长回文子串
   - [题目](editor/cn/doc/content/P5_LongestPalindromicSubstring.md)  [程序](editor/cn/P5_LongestPalindromicSubstring.cpp) [笔记](editor/cn/doc/note/P5_LongestPalindromicSubstring.md)
   
     >执行耗时:8 ms,击败了97.28% 的C++用户
     >内存消耗:6.7 MB,击败了85.55% 的C++用户
   
4. 三数之和
   - [题目](editor/cn/doc/content/P15_ThreeSum.md)  [程序](editor/cn/P15_ThreeSum.cpp) [笔记](editor/cn/doc/note/P15_ThreeSum.md)
   
	  >执行耗时:88 ms,击败了40.60% 的C++用户
	  >内存消耗:35.1 MB,击败了6.66% 的C++用户
	
5. 有效的括号
   - [题目](editor/cn/doc/content/P20_ValidParentheses.md)  [程序](editor/cn/P20_ValidParentheses.cpp) [笔记](editor/cn/doc/note/P20_ValidParentheses.md)
   
	  >执行耗时:0 ms,击败了100.00% 的C++用户
	  >内存消耗:6 MB,击败了97.88% 的C++用户
6. 合并两个有序链表
   - [题目](editor/cn/doc/content/P21_MergeTwoSortedLists.md)  [程序](editor/cn/P21_MergeTwoSortedLists.cpp) [笔记](editor/cn/doc/note/P21_MergeTwoSortedLists.md)
   
	  >执行耗时:8 ms,击败了57.82% 的C++用户
	  >内存消耗:14.4 MB,击败了34.20% 的C++用户

7.  合并K个升序链表
    - [题目](editor/cn/doc/content/P23_MergeKSortedLists.md)  [程序](editor/cn/P23_MergeKSortedLists.cpp) [笔记](editor/cn/doc/note/P23_MergeKSortedLists.md)
    
	  >执行耗时:24 ms,击败了52.73% 的C++用户
	  >内存消耗:13.5 MB,击败了21.58% 的C++用户

8.  两两交换链表中的节点
    - [题目](editor/cn/doc/content/P24_SwapNodesInPairs.md)  [程序](editor/cn/P24_SwapNodesInPairs.cpp) [笔记](editor/cn/doc/note/P24_SwapNodesInPairs.md)
    
	  >执行耗时:0 ms,击败了100.00% 的C++用户
	  >内存消耗:7.3 MB,击败了60.08% 的C++用户

9.  K个一组翻转链表
    - [题目](editor/cn/doc/content/P25_ReverseNodesInKGroup.md)  [程序](editor/cn/P25_ReverseNodesInKGroup.cpp) [笔记](editor/cn/doc/note/P25_ReverseNodesInKGroup.md)
    
	  >执行耗时:8 ms,击败了98.20% 的C++用户 
	  >内存消耗:11.2 MB,击败了47.15% 的C++用户

10.  有效的数独
     - [题目](editor/cn/doc/content/P36_ValidSudoku.md)  [程序](editor/cn/P36_ValidSudoku.cpp) [笔记](editor/cn/doc/note/P36_ValidSudoku.md)
     
	   >执行耗时:12 ms,击败了93.59% 的C++用户 
	   >内存消耗:17.9 MB,击败了31.46% 的C++用户

11.  接雨水
     - [题目](editor/cn/doc/content/P42_TrappingRainWater.md)  [程序](editor/cn/P42_TrappingRainWater.cpp) [笔记](editor/cn/doc/note/P42_TrappingRainWater.md)
     
	   >执行耗时:12 ms,击败了81.23% 的C++用户
	   >内存消耗:19.1 MB,击败了96.21% 的C++用户

12.  字符串相乘
     - [题目](editor/cn/doc/content/P43_MultiplyStrings.md)  [程序](editor/cn/P43_MultiplyStrings.cpp) [笔记](editor/cn/doc/note/P43_MultiplyStrings.md)
     
	   >执行耗时:16 ms,击败了33.38% 的C++用户
	   >内存消耗:12 MB,击败了13.17% 的C++用户

13.  旋转图像
     - [题目](editor/cn/doc/content/P48_RotateImage.md)  [程序](editor/cn/P48_RotateImage.cpp) [笔记](editor/cn/doc/note/P48_RotateImage.md)
     
	   >执行耗时:0 ms,击败了100.00% 的C++用户
	   >内存消耗:6.8 MB,击败了70.89% 的C++用户

14.  通配符匹配
     - [题目](editor/cn/doc/content/P44_WildcardMatching.md)  [程序](editor/cn/P44_WildcardMatching.cpp) [笔记](editor/cn/doc/note/P44_WildcardMatching.md)
     
	   >执行耗时:52 ms,击败了79.64% 的C++用户
	   >内存消耗:10.9 MB,击败了71.50% 的C++用户

15.  二叉树的中序遍历
     - [题目](editor/cn/doc/content/P94_BinaryTreeInorderTraversal.md)  [程序](editor/cn/P94_BinaryTreeInorderTraversal.cpp) [笔记](editor/cn/doc/note/P94_BinaryTreeInorderTraversal.md)
     
	   >执行耗时:0 ms,击败了100.00% 的C++用户
	   >内存消耗:8 MB,击败了92.66% 的C++用户

16.  验证二叉搜索树
     - [题目](editor/cn/doc/content/P98_ValidateBinarySearchTree.md)  [程序](editor/cn/P98_ValidateBinarySearchTree.cpp) [笔记](editor/cn/doc/note/P98_ValidateBinarySearchTree.md)
     
	   >执行耗时:4 ms,击败了98.02% 的C++用户
	   >内存消耗:21.1 MB,击败了76.74% 的C++用户

17.  二叉树的层序遍历
     - [题目](editor/cn/doc/content/P102_BinaryTreeLevelOrderTraversal.md)  [程序](editor/cn/P102_BinaryTreeLevelOrderTraversal.cpp) [笔记](editor/cn/doc/note/P102_BinaryTreeLevelOrderTraversal.md)
     
	   >执行耗时:0 ms,击败了100.00% 的C++用户
	   >内存消耗:12.1 MB,击败了83.76% 的C++用户

18.  可以到达所有点的最少点数目
     - [题目](editor/cn/doc/content/P1557_MinimumNumberOfVerticesToReachAllNodes.md)  [程序](editor/cn/P1557_MinimumNumberOfVerticesToReachAllNodes.cpp) [笔记](editor/cn/doc/note/P1557_MinimumNumberOfVerticesToReachAllNodes.md)
     
	   >执行耗时:232 ms,击败了72.26% 的C++用户
	   >内存消耗:91.6 MB,击败了89.42% 的C++用户

19.  寻找图中是否存在路径
     - [题目](editor/cn/doc/content/P1971_FindIfPathExistsInGraph.md)  [程序](editor/cn/P1971_FindIfPathExistsInGraph.cpp) [笔记](editor/cn/doc/note/P1971_FindIfPathExistsInGraph.md)
     
	   >执行耗时:296 ms,击败了93.21% 的C++用户
	   >内存消耗:115.7 MB,击败了69.11% 的C++用户


20.  省份数量
     - [题目](editor/cn/doc/content/P547_NumberOfProvinces.md)  [程序](editor/cn/P547_NumberOfProvinces.cpp) [笔记](editor/cn/doc/note/P547_NumberOfProvinces.md)
     
	   >执行耗时:16 ms,击败了92.94% 的C++用户
	   >内存消耗:13.3 MB,击败了54.74% 的C++用户

21.  冗余连接
     - [题目](editor/cn/doc/content/P684_RedundantConnection.md)  [程序](editor/cn/P684_RedundantConnection.cpp) [笔记](editor/cn/doc/note/P684_RedundantConnection.md)
     
	   >执行耗时:4 ms,击败了95.21% 的C++用户
	   >内存消耗:8.5 MB,击败了55.76% 的C++用户

22.  冗余连接Ⅱ
     - [题目](editor/cn/doc/content/P685_RedundantConnectionIi.md)  [程序](editor/cn/P685_RedundantConnectionIi.cpp) [笔记](editor/cn/doc/note/P685_RedundantConnectionIi.md)
     
	   >执行耗时:4 ms,击败了97.05% 的C++用户
	   >内存消耗:9.3 MB,击败了43.46% 的C++用户

23.  连接所有点的最小费用
     - [题目](editor/cn/doc/content/P1584_MinCostToConnectAllPoints.md)  [程序](editor/cn/P1584_MinCostToConnectAllPoints.cpp) [笔记](editor/cn/doc/note/P1584_MinCostToConnectAllPoints.md)
     
	   >执行耗时:48 ms,击败了98.79% 的C++用户
	   >内存消耗:10.2 MB,击败了94.74% 的C++用户

24.  网络延迟时间
     - [题目](editor/cn/doc/content/P743_NetworkDelayTime.md)  [程序](editor/cn/P743_NetworkDelayTime.cpp) [笔记](editor/cn/doc/note/P743_NetworkDelayTime.md)
     
	   >执行耗时:88 ms,击败了86.19% 的C++用户
	   >内存消耗:36.9 MB,击败了61.38% 的C++用户

24.  二叉搜索树中的插入操作
     - [题目](editor/cn/doc/content/P701_InsertIntoABinarySearchTree.md)  [程序](editor/cn/P701_InsertIntoABinarySearchTree.cpp) [笔记](editor/cn/doc/note/P701_InsertIntoABinarySearchTree.md)
     
	   >执行耗时:80 ms,击败了80.70% 的C++用户
	   >内存消耗:55.6 MB,击败了36.51% 的C++用户

25.  平衡二叉树
     - [题目](editor/cn/doc/content/P110_BalancedBinaryTree.md)  [程序](editor/cn/P110_BalancedBinaryTree.cpp) [笔记](editor/cn/doc/note/P110_BalancedBinaryTree.md)
     
	   >执行耗时:8 ms,击败了87.63% 的C++用户
	   >内存消耗:20.5 MB,击败了17.05% 的C++用户

26.  排序数组
     - [题目](editor/cn/doc/content/P912_SortAnArray.md)  [程序](editor/cn/P912_SortAnArray.cpp) [笔记](editor/cn/doc/note/P912_SortAnArray.md)
     
	   >执行耗时:84 ms,击败了96.94% 的C++用户
	   >内存消耗:54 MB,击败了99.91% 的C++用户

27.  柱状图中最大的矩形
     - [题目](editor/cn/doc/content/P84_LargestRectangleInHistogram.md)  [程序](editor/cn/P84_LargestRectangleInHistogram.cpp) [笔记](editor/cn/doc/note/P84_LargestRectangleInHistogram.md)
     
	   >执行耗时:116 ms,击败了89.45% 的C++用户
	   >内存消耗:73 MB,击败了99.07% 的C++用户

29.  最大矩形
     - [题目](editor/cn/doc/content/P85_MaximalRectangle.md)  [程序](editor/cn/P85_MaximalRectangle.cpp) [笔记](editor/cn/doc/note/P85_MaximalRectangle.md)
     
	   >执行耗时:36 ms,击败了83.19% 的C++用户
	   >内存消耗:15.1 MB,击败了34.08% 的C++用户

30.  比特位计数
     - [题目](editor/cn/doc/content/P338_CountingBits.md)  [程序](editor/cn/P338_CountingBits.cpp) [笔记](editor/cn/doc/note/P338_CountingBits.md)
     
	   >执行耗时:4 ms,击败了88.05% 的C++用户
	   >内存消耗:7.5 MB,击败了97.75% 的C++用户

32. 寻找峰值
     - [题目](editor/cn/doc/content/P162_FindPeakElement.md)  [程序](editor/cn/P162_FindPeakElement.cpp) [笔记](editor/cn/doc/note/P162_FindPeakElement.md)
    
	   >执行耗时:4 ms,击败了72.56% 的C++用户
	   >内存消耗:8.7 MB,击败了8.64% 的C++用户
	
33.  全排列
     - [题目](editor/cn/doc/content/P46_Permutations.md)  [程序](editor/cn/P46_Permutations.cpp) [笔记](editor/cn/doc/note/P46_Permutations.md)
     
	   >执行耗时:0 ms,击败了100.00% 的C++用户
	   >内存消耗:7.1 MB,击败了99.95% 的C++用户

34.  全排列 II
     - [题目](editor/cn/doc/content/P47_PermutationsIi.md)  [程序](editor/cn/P47_PermutationsIi.cpp) [笔记](editor/cn/doc/note/P47_PermutationsIi.md)
     
	   >执行耗时:4 ms,击败了92.96% 的C++用户
	   >内存消耗:8.4 MB,击败了83.09% 的C++用户

35.  N 皇后
     - [题目](editor/cn/doc/content/P51_NQueens.md)  [程序](editor/cn/P51_NQueens.cpp) [笔记](editor/cn/doc/note/P51_NQueens.md)
     
	   >执行耗时:4 ms,击败了93.37% 的C++用户
	   >内存消耗:7 MB,击败了93.65% 的C++用户

36.  跳跃游戏
     - [题目](editor/cn/doc/content/P55_JumpGame.md)  [程序](editor/cn/P55_JumpGame.cpp) [笔记](editor/cn/doc/note/P55_JumpGame.md)
     
	   >执行耗时:40 ms,击败了95.53% 的C++用户
	   >内存消耗:47.2 MB,击败了37.50% 的C++用户

37.  不同路径
     - [题目](editor/cn/doc/content/P62_UniquePaths.md)  [程序](editor/cn/P62_UniquePaths.cpp) [笔记](editor/cn/doc/note/P62_UniquePaths.md)
     
	   >执行耗时:0 ms,击败了100.00% 的C++用户
	   >内存消耗:5.7 MB,击败了95.55% 的C++用户

38.  不同路径 II
     - [题目](editor/cn/doc/content/P63_UniquePathsIi.md)  [程序](editor/cn/P63_UniquePathsIi.cpp) [笔记](editor/cn/doc/note/P63_UniquePathsIi.md)
     
	   >执行耗时:0 ms,击败了100.00% 的C++用户
	   >内存消耗:7.5 MB,击败了69.79% 的C++用户

39.  x 的平方根
     - [题目](editor/cn/doc/content/P69_Sqrtx.md)  [程序](editor/cn/P69_Sqrtx.cpp) [笔记](editor/cn/doc/note/P69_Sqrtx.md)
     
	   >执行耗时:0 ms,击败了100.00% 的C++用户
	   >内存消耗:5.8 MB,击败了38.18% 的C++用户

39.  Pow(x, n)
     - [题目](editor/cn/doc/content/P50_PowxN.md)  [程序](editor/cn/P50_PowxN.cpp) [笔记](editor/cn/doc/note/P50_PowxN.md)
     
	   >执行耗时:0 ms,击败了100.00% 的C++用户
	   >内存消耗:5.9 MB,击败了32.06% 的C++用户

40.  旋转链表
     - [题目](editor/cn/doc/content/P61_RotateList.md)  [程序](editor/cn/P61_RotateList.cpp) [笔记](editor/cn/doc/note/P61_RotateList.md)
     
	   >执行耗时:8 ms,击败了64.06% 的C++用户
	   >内存消耗:11.4 MB,击败了32.96% 的C++用户

41.  直线上最多的点数
     - [题目](editor/cn/doc/content/P149_MaxPointsOnALine.md)  [程序](editor/cn/P149_MaxPointsOnALine.cpp) [笔记](editor/cn/doc/note/P149_MaxPointsOnALine.md)
     
	   >执行耗时:8 ms,击败了100.00% 的C++用户
	   >内存消耗:9.5 MB,击败了78.74% 的C++用户

42.  矩阵中的路径
     - [题目](editor/cn/doc/content/JuZhenZhongDeLuJingLcof.md)  [程序](editor/cn/JuZhenZhongDeLuJingLcof.cpp) [笔记](editor/cn/doc/note/JuZhenZhongDeLuJingLcof.md)
     
	   >执行耗时:148 ms,击败了97.62% 的C++用户
	   >内存消耗:6.2 MB,击败了29.96% 的C++用户

43.  O(1) 时间插入、删除和获取随机元素
     - [题目](editor/cn/doc/content/P380_InsertDeleteGetrandomO1.md)  [程序](editor/cn/P380_InsertDeleteGetrandomO1.cpp) [笔记](editor/cn/doc/note/P380_InsertDeleteGetrandomO1.md)
     
	   >执行耗时:184 ms,击败了84.05% 的C++用户
	   >内存消耗:94.8 MB,击败了27.00% 的C++用户

44.  颜色分类
     - [题目](editor/cn/doc/content/P75_SortColors.md)  [程序](editor/cn/P75_SortColors.cpp) [笔记](editor/cn/doc/note/P75_SortColors.md)
     
	   >执行耗时:0 ms,击败了100.00% 的C++用户
	   >内存消耗:8 MB,击败了47.63% 的C++用户

45.  杨辉三角
     - [题目](editor/cn/doc/content/P118_PascalsTriangle.md)  [程序](editor/cn/P118_PascalsTriangle.cpp) [笔记](editor/cn/doc/note/P118_PascalsTriangle.md)
     
	   >执行耗时:0 ms,击败了100.00% 的C++用户
	   >内存消耗:6.5 MB,击败了70.22% 的C++用户

46.  杨辉三角 II
     - [题目](editor/cn/doc/content/P119_PascalsTriangleIi.md)  [程序](editor/cn/P119_PascalsTriangleIi.cpp) [笔记](editor/cn/doc/note/P119_PascalsTriangleIi.md)
     
	   >执行耗时:0 ms,击败了100.00% 的C++用户
	   >内存消耗:6.2 MB,击败了65.93% 的C++用户

47.  买卖股票的最佳时机
     - [题目](editor/cn/doc/content/P121_BestTimeToBuyAndSellStock.md)  [程序](editor/cn/P121_BestTimeToBuyAndSellStock.cpp) [笔记](editor/cn/doc/note/P121_BestTimeToBuyAndSellStock.md)
     
	   >执行耗时:100 ms,击败了72.07% 的C++用户
	   >内存消耗:91.3 MB,击败了31.97% 的C++用户

48.  最近的房间
     - [题目](editor/cn/doc/content/P1847_ClosestRoom.md)  [程序](editor/cn/P1847_ClosestRoom.cpp) [笔记](editor/cn/doc/note/P1847_ClosestRoom.md)
     
	   >执行耗时:744 ms,击败了10.29% 的C++用户
	   >内存消耗:172.2 MB,击败了26.47% 的C++用户

//滑动窗口的平均值