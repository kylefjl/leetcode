//给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。 
//
// 在「杨辉三角」中，每个数是它左上方和右上方的数的和。 
//
// 
//
// 
//
// 示例 1: 
//
// 
//输入: rowIndex = 3
//输出: [1,3,3,1]
// 
//
// 示例 2: 
//
// 
//输入: rowIndex = 0
//输出: [1]
// 
//
// 示例 3: 
//
// 
//输入: rowIndex = 1
//输出: [1,1]
// 
//
// 
//
// 提示: 
//
// 
// 0 <= rowIndex <= 33 
// 
//
// 
//
// 进阶： 
//
// 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？ 
//
// Related Topics 数组 动态规划 👍 479 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 杨辉三角 II
* @author name
* @date 2023-04-01 23:55:19
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        int level = 1;//此时的rowIndex是从第0层开始算的，所以统一从0开始
        vector<vector<int>> result;
        vector<int> lastLevel = {1};//添加第0层 {1}
        while (level <=rowIndex)
        {
            auto temp = lastLevel;
            for (int i = 1; i < lastLevel.size(); ++i)
            {
                lastLevel[i] += temp[i - 1];//错位相加
            }
            lastLevel.push_back(1);//手动添加每层最后的1
            level++;
        }
        return lastLevel;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
}