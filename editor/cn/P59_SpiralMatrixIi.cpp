//给你一个正整数 n ，生成一个包含 1 到 n² 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：n = 3
//输出：[[1,2,3],[8,9,4],[7,6,5]]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 
//
// Related Topics 数组 矩阵 模拟 👍 1254 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 螺旋矩阵 II
* @author fjl
* @date 2024-02-23 14:50:56
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;//定义边界 (每此循环一层)
        int num = 1;
        while (left<right&&top<bottom)//当左边界小于右边界并且上边界小于下边界时
        {
            int i=top,j=left;
            for(j=left;j<right;++j)res[i][j]=num++;//从左到右 [) 左闭右开
            for(i=top;i<bottom;++i)res[i][j]=num++;//从上到下
            for(j=right;j>left;--j)res[i][j]=num++;//从右到左
            for(i=bottom;i>top;--i)res[i][j]=num++;//从下到上
            left++;// 左边界+1
            right--;
            top++;
            bottom--;
        }
        if (left==right&&top==bottom)//当左边界等于右边界并且上边界等于下边界时 说明是奇数 且是最后一个 只有一个元素
        {
            res[left][top]=num;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    auto res=s.generateMatrix(3);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}