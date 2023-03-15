# 不同路径 II

## 动态规划

与p62类似，增加了个障碍物判断

```cc
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
```

