# 全排列 II

与P46相同，需要特别考虑的点是重复的数，思路是

>
>
>要解决重复问题，我们只要设定一个规则，保证在填第 *idx* 个数的时候**重复数字只会被填入一次即可**。而在本题解中，我们选择对原数组排序，保证相同的数字都相邻，然后每次填入的数一定是这个数所在重复数集合中「从左往右第一个未被填过的数字」，即如下的判断条件：
>
>- [sol0-C++]
>
>```C++
>if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) {
>    continue;
>}
>```
>
>这个判断条件保证了对于重复数的集合，一定是从左往右逐个填入的。
>
>假设我们有 3 个重复数排完序后相邻，那么我们一定保证每次都是拿从左往右第一个未被填过的数字，即整个数组的状态其实是保证了 [未填入，未填入，未填入] 到 [填入，未填入，未填入]，再到 [填入，填入，未填入]，最后到 [填入，填入，填入] 的过程的，因此可以达到去重的目标。

```cc
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
```

>执行耗时:4 ms,击败了92.96% 的C++用户
>内存消耗:8.4 MB,击败了83.09% 的C++用户