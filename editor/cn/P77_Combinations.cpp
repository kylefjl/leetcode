//给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。 
//
// 你可以按 任何顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4, k = 2
//输出：
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
//
// 示例 2： 
//
// 
//输入：n = 1, k = 1
//输出：[[1]] 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
//
// Related Topics 回溯 👍 1595 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 组合
* @author fjl
* @date 2024-03-09 15:45:22
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return result;


    }
    void backtracking(int n,int k,int startIndex)
    {
        if(path.size()==k)
        {
            result.push_back(path);
            return ;
        }
        for(int i=startIndex;i<=n;i++)
        {
            path.push_back(i);
            backtracking(n,k,i+1);
            path.pop_back();
        }
    }
private:
    vector<vector<int>> result;
    vector<int> path;
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    vector<vector<int>> result = s.combine(4,2);
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}