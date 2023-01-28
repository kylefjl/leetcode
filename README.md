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