//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1]
//输出：[[0,1],[1,0]]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1]
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// nums 中的所有整数 互不相同 
// 
//
// Related Topics 数组 回溯 👍 2394 👎 0

#include<bits/stdc++.h>
#include"MyHead.h"
using namespace std;

/*
* 全排列
* @author fjl
* @date 2023-02-09 17:36:32
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
        int permute_num=factorial(length);//总的排列数
        result.reserve(permute_num);//预留空间
        backrack(result,nums,1,nums.size());//默认首位的数字确定，从第二位开始尝试，减少递归次数
        const int temp_size=result.size();//即（length-1）的阶乘
        for (int i = 0; i < temp_size; ++i)
        {
            for (int j = 1; j <length ; ++j)//再复制length-1次，并把第一位和后面的几位分别进行交换，得到全排列
            {
                result.push_back(result[i]);
                swap(result.back()[0],result.back()[j]);
            }
        }
        return result;
    }
    void backrack(vector<vector<int>>& res,vector<int>& output,int first,int len)
    {
        if(first==len)//排列完毕
        {
            res.push_back(output);//添加到结果中
            return;
        }
        for(int i=first;i<len;++i)//将每个没有填过的数都试一下
        {
            swap(output[first],output[i]);//选择一个数放到first的位置
            backrack(res,output,first+1,len);//将first标记为确定并继续排列
            swap(output[first],output[i]);//枚举完之后撤销操作
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;

   vector<int > input={0,1,2,3,5,6,7,8,9,10};
    TimeCost timeCost("permute");
    auto result=s.permute2(input);
    timeCost.toc();
    return 0;
}