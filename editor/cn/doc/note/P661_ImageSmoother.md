# 图片平滑器

## 遍历

4层for循环

略

## 前缀和



对于某个 `ans[i][j]`而言，我们可以直接计算出其所在 item 的左上角$(a,b)=(i-1,j-1)$以及其右下角 $(c,d)=(i + 1, j + 1)$，同时为了防止超出原矩阵，我们需要将 (a, b) 与 (c, d) 对边界分别取 max 和 min。当有了合法的 (a, b) 和 (c, d)后，我们可以直接计算出 item 的单元格数量（所包含的行列乘积）及 item 的单元格之和（前缀和查询），从而算得 `ans[i][j]`。









```c++
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> res(img.size(), vector<int>(img[0].size(), 0));
         int m = img.size();//行
         int n = img[0].size();//列
        vector<vector<long  int>> sums(m+1,vector<long int>(n+1,0));//前缀和
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                //前缀和
                sums[i+1][j+1] = sums[i][j+1] + sums[i+1][j] - sums[i][j] + img[i][j];
            }
        }
        int x1,y1,x2,y2,cnt;
#define max(a,b) (a>b?a:b)//宏定义
#define min(a,b) (a<b?a:b)//宏定义
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                 x1=max(0, i-1),y1=max(0, j-1),x2=min(m-1, i+1),y2=min(n-1, j+1);//边界处理
                 cnt = (x2 - x1+1) * (y2 - y1+1);//计算窗内个数
                res[i][j] = floor((sums[x2+1][y2+1] - sums[x1][y2+1] -sums[x2+1][y1] + sums[x1][y1])/cnt);//计算平均值
            }
        }
#undef max
#undef min
        return res;
    }
};
```

