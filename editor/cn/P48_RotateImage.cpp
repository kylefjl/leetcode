//给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。 
//
// 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。 
//
// 
//
// 示例 1： 
// 
// 
//输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[[7,4,1],[8,5,2],[9,6,3]]
// 
//
// 示例 2： 
// 
// 
//输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
//输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
// 
//
// 
//
// 提示： 
//
// 
// n == matrix.length == matrix[i].length 
// 1 <= n <= 20 
// -1000 <= matrix[i][j] <= 1000 
// 
//
// 
//
// Related Topics数组 | 数学 | 矩阵 
//
// 👍 1530, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//

#include<bits/stdc++.h>
using namespace std;

/*
* 旋转图像
* @author name
* @date 2023-01-19 23:37:44
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        const int n_high=ceil(matrix.size()/2);//向上取整
        const int n_low=matrix.size()/2;//向下取整
        const int max_idx=matrix.size()-1;//用常量存储矩阵索引的最大值
        int temp=0;
        for(int i=n_high-1;i>=0;--i)//边界分别选取0.5size的向上取整和向下取整，保证遍历全部
        {
            for(int j=0 ;j<n_low;++j)
            {
                //一次移动4个数据
                temp=matrix[i][j];
                matrix[i][j]=matrix[max_idx-j][i];
                matrix[max_idx-j][i] = matrix[max_idx-i][max_idx-j];
                matrix[max_idx-i][max_idx-j] = matrix[j][max_idx-i];
                matrix[j][max_idx-i] = temp;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

//void rotate(vector<vector<int>>& matrix)
//{
//    vector<vector<int>> temp_mat=matrix;
//    const int n=matrix.size()-1;
//    for(int i=0 ;i<=n;++i)
//    {
//        for(int j=0 ;j<=n;++j)
//        {
//            temp_mat[j][n-i]=matrix[i][j];
//        }
//    }
//    matrix=temp_mat;
//}
int main()
{
   Solution s;
   vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(mat);
    for(auto & i : mat)
    {
//            temp_col.reserve(matrix[0].size());
        for(int j : i)
        {
            cout<<j<<' ';
        }
        cout<<endl;
    }
}