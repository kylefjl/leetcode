//一个机器人位于一个
// m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。 
//
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。 
//
// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？ 
//
// 网格中的障碍物和空位置分别用 1 和 0 来表示。 
//
// 
//
// 示例 1： 
// 
// 
//输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
//输出：2
//解释：3x3 网格的正中间有一个障碍物。
//从左上角到右下角一共有 2 条不同的路径：
//1. 向右 -> 向右 -> 向下 -> 向下
//2. 向下 -> 向下 -> 向右 -> 向右
// 
//
// 示例 2： 
// 
// 
//输入：obstacleGrid = [[0,1],[0,0]]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// m == obstacleGrid.length 
// n == obstacleGrid[i].length 
// 1 <= m, n <= 100 
// obstacleGrid[i][j] 为 0 或 1 
// 
//
// Related Topics 数组 动态规划 矩阵 👍 983 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 不同路径 II
* @author name
* @date 2023-03-12 00:13:29
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m= obstacleGrid.size();
        const int n=obstacleGrid[0].size();
        vector<vector<int>> table(m,vector<int>(n,0));//创建动态表，每一点上的数代表有多少条不同的路径可以到达该点
        for (int i = 0; i < m; ++i)
        {
            if (obstacleGrid[i][0]==1)break;//如果碰到障碍，则后面的点都到达不了，退出
            table[i][0]=1;//上边和左边上的点都只有一条路径到达。

        }
        for (int i = 0; i < n; ++i)
        {
            if (obstacleGrid[0][i]==1)break;
            table[0][i]=1;
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j]==0)//如果没有障碍，则计算路径数，如果有障碍，则路径数为0；
                table[i][j]=table[i][j-1]+table[i-1][j];//到达该点的路径等于从左边点过来的路径和从上边点过来的路径和
            }
        }
        return table[m-1][n-1];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   vector<vector<int>> input={{0,0,0},{0,1,0},{0,0,0}};
   cout<<s.uniquePathsWithObstacles(input);
}