# 不同路径

## 组合方法

从左上角到右下角的过程中，我们需要移动 $m+n-2$ 次，其中有 m-1 次向下移动，n-1 次向右移动。因此路径的总数，就等于从 m+n-2 次移动中选择 m-1 次或n-1的方案数，即组合数：

$$C^{m+n−2}_{m−1}=\dfrac{(m+n−2)(m+n−3)⋯n}{(m−1)!}=\dfrac{(m+n−2)!}{(m−1)!(n−1)!}$$



```cc
class Solution {
public:
    int uniquePaths(int m, int n) {//相当于求组合 c(m+n-2)(min(m-1,n-1))
        unsigned long int ans=1;//避免越界
        for (int i =0; i <min(m-1,n-1) ; ++i)
        {
            ans=ans*(m+n-2-i)/(i+1);//每次分子分母都分别乘一个数，因为ans是int，要保证分子/分母可以整除
        }
        return ans;
    }
};
```

> 执行耗时:0 ms,击败了100.00% 的C++用户
> 内存消耗:5.7 MB,击败了95.55% 的C++用户

## 动态规划

到达该点的路径等于从左边点过来的路径和从上边点过来的路径和，即==当前状态只与子状态(左、上)有关==

```cc
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
```

