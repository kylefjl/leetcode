# 全排列

回溯法

[全排列 - 全排列 - 力扣（LeetCode）](https://leetcode.cn/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/)

优化：默认首位的数字确定，从第二位开始尝试，已减少递归次数 ，得到结果后再将其复制nums.length-1次，并把第一位和后面的几位分别进行交换，得到全排列

```cc
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
```

>执行耗时:0 ms,击败了100.00% 的C++用户
>内存消耗:7.1 MB,击败了99.95% 的C++用户