//图像平滑器 是大小为 3 x 3 的过滤器，用于对图像的每个单元格平滑处理，平滑处理后单元格的值为该单元格的平均灰度。 
//
// 每个单元格的 平均灰度 定义为：该单元格自身及其周围的 8 个单元格的平均值，结果需向下取整。（即，需要计算蓝色平滑器中 9 个单元格的平均值）。 
//
// 如果一个单元格周围存在单元格缺失的情况，则计算平均灰度时不考虑缺失的单元格（即，需要计算红色平滑器中 4 个单元格的平均值）。 
//
// 
//
// 给你一个表示图像灰度的 m x n 整数矩阵 img ，返回对图像的每个单元格平滑处理后的图像 。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入:img = [[1,1,1],[1,0,1],[1,1,1]]
//输出:[[0, 0, 0],[0, 0, 0], [0, 0, 0]]
//解释:
//对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
//对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
//对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
// 
//
// 示例 2: 
// 
// 
//输入: img = [[100,200,100],[200,50,200],[100,200,100]]
//输出: [[137,141,137],[141,138,141],[137,141,137]]
//解释:
//对于点 (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
//
//对于点 (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.
//666667) = 141
//对于点 (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) =
// 138
// 
//
// 
//
// 提示: 
//
// 
// m == img.length 
// n == img[i].length 
// 1 <= m, n <= 200 
// 0 <= img[i][j] <= 255 
// 
//
// Related Topics 数组 矩阵 👍 200 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 图片平滑器
* @author name
* @date 2023-05-04 16:51:51
*/
//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    vector<vector<int>> img = {{1,1,1},{1,0,1},{1,1,1}};

    auto res=s.imageSmoother(img);
    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res[0].size(); ++j)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

}