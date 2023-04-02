//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。 
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
//输入: numRows = 5
//输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// 
//
// 示例 2: 
//
// 
//输入: numRows = 1
//输出: [[1]]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= numRows <= 30 
// 
//
// Related Topics 数组 动态规划 👍 957 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 杨辉三角
* @author name
* @date 2023-04-01 23:25:32
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int level=2;//第一层不用算，直接开始第二层
        vector<vector<int>> result;
        result.push_back({1});//添加第一层 {1}
        while (level<=numRows)
        {
            auto temp=result.back();
            for(int i=1;i<temp.size();++i)
            {
                temp[i]+=result.back()[i-1];//错位相加
            }
            temp.push_back(1);//手动添加每层最后的1
            result.push_back(std::move(temp));
            level++;
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   auto result=s.generate(5);

}