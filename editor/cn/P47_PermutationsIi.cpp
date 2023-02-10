//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
//
// Related Topics 数组 回溯 👍 1287 👎 0

#include<bits/stdc++.h>
#include "MyHead.h"
using namespace std;

/*
* 全排列 II
* @author fjl
* @date 2023-02-10 17:29:06
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()==0)return {};
        auto factorial=[](int n)//lamda 表达式 计算阶乘
        {
            auto f_impl=[](int n,const auto & impl) ->int
            {
                return n>1?(n)*impl(n-1,impl):1;
            };
            return f_impl(n,f_impl);
        };
        const int length= nums.size();
        vis.resize(length);
        std::fill(vis.begin(), vis.end(),false);//初始化默认都没有使用过
        int permute_num=factorial(length);//总的排列数
        result.reserve(permute_num);//预留空间
        sort(nums.begin(),nums.end());//排序，使重复的数排列在一起
        vector<int> perm;//每次存储一种排序的结果
        backrack(result,nums,perm,length,0);//idx 为perm中已经排列的个数
        return result;
    }
//回溯法，res存储所有排序的结果，perm每次存储一种排序的结果，idx 为perm中已经排列的个数
    void backrack(vector<vector<int>>& res,vector<int>& nums,vector<int>& perm,int len,int idx)
    {
        if(idx==len)//排列完毕
        {
            res.push_back(perm);//添加到结果中
            return;
        }
        for(int i=0;i<len;++i)//将每个数都试一下
        {
            if(vis[i]||(i>0&&!vis[i-1]&&nums[i-1]==nums[i]))
            {//如果这个数已经使用过，或这个数和它的上一个数重复且上一个没被使用
                continue;
            }
            vis[i]=true;//选择一个数放到perm
            perm.emplace_back(nums[i]);
            backrack(res,nums,perm,len,idx+1);//将first标记为确定并继续排列
            vis[i]=false;
            perm.pop_back();;//枚举完之后撤销操作
        }
    }
private:
    vector<bool> vis;//标记是否已经使用过这个数字
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    vector<int > input={0,1,2};
    TimeCost timeCost("permuteUnique");
    auto result=s.permuteUnique(input);
    timeCost.toc();
}