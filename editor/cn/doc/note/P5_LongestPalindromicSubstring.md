# 最长回文子串

该题的一个要点是实现查找回文的功能，主要思路是从中心扩展，具体可以看函数`expandAroundCenter`。

但是，这样计算复杂度还是很高，其实可以从“最长”一词出发，在查找回文之前判断其是否有可能比之前找到的还长，这样可以减少大量的计算。

> 2023/01/13 19:02:42	
> 解答成功:
> 执行耗时:8 ms,击败了97.28% 的C++用户
> 内存消耗:6.7 MB,击败了85.55% 的C++用户

```cc
class Solution {
public:
    string longestPalindrome(string s)
    {
        int begin_idx=0,length_max=1;//记录最长的回文位置
        int i_single_length=0,i_double_length=0;//记录查找到的奇偶回文长度
        for(int i=0;i<s.size();i++)
        {
            //如果有更长的奇回文，则i_begin和i_end对应位置的字符应该相等，否则肯定小于等于当前的length_max
            int i_begin=(i-length_max/2-length_max%2),i_end=(i+length_max/2+length_max%2);
            if(i_begin>=0&&i_end<s.size())//防止访问越界
            {
                if (s[i_begin] == s[i_end])//相等，有可能出现更长的奇回文
                {//查找回文子串长度
                    i_single_length = expandAroundCenter(s, i, i);
                }
            }
            //如果有更长的偶回文，则i_begin+1和i_end对应位置的字符应该相等，否则肯定小于等于当前的length_max
            if(i_begin+1>=0&&i_end<s.size())//防止访问越界
            {
                if(s[i_begin+1] == s[i_end])//相等，有可能出现更长的偶回文
                {//查找回文子串长度
                    i_double_length= expandAroundCenter(s,i,i+1);
                }
            }
            if(i_single_length>length_max||i_double_length>length_max)//如果出现更长的，则更新length_max
            {
                length_max=max(i_single_length,i_double_length);
                begin_idx=i-length_max/2-length_max%2+1;//记录开始位置
            }
        }
        return s.substr(begin_idx,length_max);
    }
    //以输入的参数为中心查找回文，如果left=right，则查找奇数长度的回文，如果right-left=1，则查找偶数长度的回文
    int  expandAroundCenter(const string& s, int left, int right)
    {
        int length=0;
        if(left>right||s[left] != s[right])return 0;//左边大于右边或刚开始就不相等，直接返回0
        if(left==right)//奇数长度的回文
        {
            length=1;
            --left; ++right;
        }
        else if(right-left==1)//偶数长度的回文
        {
            length=0;
        }
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left; ++right;
            length+=2;
        }
        return length;
    }
};
```

