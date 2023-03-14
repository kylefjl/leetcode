//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。 
//
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。 
//
// 问总共有多少条不同的路径？ 
//
// 
//
// 示例 1： 
// 
// 
//输入：m = 3, n = 7
//输出：28 
//
// 示例 2： 
//
// 
//输入：m = 3, n = 2
//输出：3
//解释：
//从左上角开始，总共有 3 条路径可以到达右下角。
//1. 向右 -> 向下 -> 向下
//2. 向下 -> 向下 -> 向右
//3. 向下 -> 向右 -> 向下
// 
//
// 示例 3： 
//
// 
//输入：m = 7, n = 3
//输出：28
// 
//
// 示例 4： 
//
// 
//输入：m = 3, n = 3
//输出：6 
//
// 
//
// 提示： 
//
// 
// 1 <= m, n <= 100 
// 题目数据保证答案小于等于 2 * 10⁹ 
// 
//
// Related Topics 数学 动态规划 组合数学 👍 1703 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 不同路径
* @author name
* @date 2023-03-14 10:29:59
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> table(m,vector<int>(n,0));//创建动态表，每一点上的数代表有多少条不同的路径可以到达该点
        for (int i = 0; i < m; ++i) table[i][0]=1;//上边和左边上的点都只有一条路径到达。
        for (int i = 0; i < n; ++i) table[0][i]=1;
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                table[i][j]=table[i][j-1]+table[i-1][j];//到达该点的路径等于从左边点过来的路径和从上边点过来的路径和
            }
        }
        return table[m-1][n-1];
    }
//    int uniquePaths_arrange(int m, int n) {//相当于求组合 c(m+n-2)(min(m-1,n-1))
////        unsigned long int ans=1;//避免越界
////        for (int i =0; i <min(m-1,n-1) ; ++i)
////        {
////            ans=ans*(m+n-2-i)/(i+1);//每次分子分母都分别乘一个数，因为ans是int，要保证分子/分母可以整除
////        }
////        return ans;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    cout<<s.uniquePaths(3,7);
}