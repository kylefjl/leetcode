//给你一个字符串 s，找到 s 中最长的回文子串。 
//
// 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出："bb"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由数字和英文字母组成 
// 
//
// Related Topics字符串 | 动态规划 
//
// 👍 6046, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//
#include<bits/stdc++.h>
using namespace std;

/*
* 最长回文子串
* @author name
* @date 2023-01-13 15:48:31
*/
//leetcode submit region begin(Prohibit modification and deletion)
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

                {
                    i_single_length = expandAroundCenter(s, i, i);
                }
            }
            //如果有更长的偶回文，则i_begin+1和i_end对应位置的字符应该相等，否则肯定小于等于当前的length_max
            if(i_begin+1>=0&&i_end<s.size())//防止访问越界
            {
                if(s[i_begin+1] == s[i_end])//相等，有可能出现更长的偶回文
                {
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
        if(left>right||s[left] != s[right])return 0;//左边大于右边或刚开始就不想等，直接返回0
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
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   string str={'b','a','b','a','d'};
   cout<<str<<endl;
   cout<<s.longestPalindrome(str)<<endl;
}