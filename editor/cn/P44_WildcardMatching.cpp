//给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。 
//
// '?' 可以匹配任何单个字符。
//'*' 可以匹配任意字符串（包括空字符串）。
// 
//
// 两个字符串完全匹配才算匹配成功。 
//
// 说明: 
//
// 
// s 可能为空，且只包含从 a-z 的小写字母。 
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。 
// 
//
// 示例 1: 
//
// 输入:
//s = "aa"
//p = "a"
//输出: false
//解释: "a" 无法匹配 "aa" 整个字符串。 
//
// 示例 2: 
//
// 输入:
//s = "aa"
//p = "*"
//输出: true
//解释: '*' 可以匹配任意字符串。
// 
//
// 示例 3: 
//
// 输入:
//s = "cb"
//p = "?a"
//输出: false
//解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
// 
//
// 示例 4: 
//
// 输入:
//s = "adceb"
//p = "*a*b"
//输出: true
//解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
// 
//
// 示例 5: 
//
// 输入:
//s = "acdcb"
//p = "a*c?b"
//输出: false 
//
// Related Topics贪心 | 递归 | 字符串 | 动态规划 
//
// 👍 983, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//

#include<bits/stdc++.h>

using namespace std;

/*
* 通配符匹配
* @author name
* @date 2023-01-19 23:35:40
*/
//leetcode submit region begin(Prohibit modification and deletion)


//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        for(int i=0;i+1<p.size();)
//        {//去除连续的*
//            if(p[i]=='*'&&p[i+1]=='*')   p.erase(i,1);
//            else ++i;
//        }
//        vector<bool> col(p.length()+1, false);
//        vector<vector<bool>> dp(s.length()+1,col);
//        const int s_size=s.length();
//        const int p_size=p.length();
//        //$dp[i][j]$表示`s[0,...,i−1]`和`p[0,...,j−1]`能匹配，
//        //如果可以则为1，否则为0，`dp[i][j]`的值和`dp[i][j-1],dp[i-1][j],dp[i-1][j-1]` 有关，
//        dp[0][0]= true;//空字符串互相匹配
//        for(int i=0;i<p_size;++i)
//        {//p的第一个为*,则p[0,1]可以和空s匹配
//            if(p[i]=='*')dp[0][i + 1] = true;
//            else break;
//        }
//        for(int i=1;i<=s_size;++i)
//        {
//            for(int j=1;j<=p_size;++j)
//            {
//                if(s[i-1]==p[j-1]||p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
//                else if(p[j-1]=='*')  dp[i][j]=dp[i][j-1]|dp[i-1][j];
//            }
//        }
//        return dp[s_size][p_size];
//    }
//};
//------------剪枝--------------------

class Solution {
public:
    bool isMatch(string s, string p) {
        for(int i=0;i+1<p.size();)
        {//去除连续的*
            if(p[i]=='*'&&p[i+1]=='*')
                p.erase(i,1);
            else ++i;
        }
        vector<bool> col(p.length()+1, false);
        vector<vector<bool>> dp(s.length()+1,col);
        const int s_size=s.length();
        const int p_size=p.length();
        //$dp[i][j]$表示`s[0,...,i−1]`和`p[0,...,j−1]`能匹配，
        //如果可以则为1，否则为0，`dp[i][j]`的值和`dp[i][j-1],dp[i-1][j],dp[i-1][j-1]` 有关，
        dp[0][0]= true;//空字符串互相匹配
        for(int i=0;i<p_size;++i)
        {
            if(p[i]=='*')
            {//p的第一个为*,则p[0,1]可以和空s匹配
                dp[0][i + 1] = true;
            }
            else break;
        }
        int begin_j=1,last_j=0;
        for(int i=1;i<=s_size;++i)
        {
            for(int j=begin_j;j<=p_size;++j)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    if(dp[i][j]=dp[i][j-1]|dp[i-1][j])
                    {
                        begin_j=j+1;//下次从*的这一列开始直接匹配下一部分
                        for(int loop_i=i+1;loop_i<=s_size;++loop_i)
                        {
                            dp[loop_i][j]=true;
                        }
                    };
                }
                else
                {
                    if(j>last_j&&j>i)
                    {//剪枝，如果上一行没有对此列之后的数进行操作，则没有必要再遍历
                        last_j=j;
                        break;
                    }
                }
                last_j=j;
            }
        }
        return dp[s_size][p_size];
    }
};


//leetcode submit region end(Prohibit modification and deletion)
//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        for(int i=0;i+1<p.size();)
//        {
//            if(p[i]=='*'&&p[i+1]=='*')
//                p.erase(i,1);
//            else ++i;
//        }
//        vector<bool> col(p.length()+1, false);
//        vector<vector<bool>> dp(s.length()+1,col);
//        const int s_size=s.length();
//        const int p_size=p.length();
//        dp[0][0]= true;
//        for(int i=0;i<p_size;++i)
//        {
//            if(p[i]=='*')
//            {
//                dp[0][i + 1] = true;
//            }
//            else break;
//        }
//        int begin_j=1,last_j=0;
//        for(int i=1;i<=s_size;++i)
//        {
//            for(int j=begin_j;j<=p_size;++j)
//            {
//                if(s[i-1]==p[j-1]||p[j-1]=='?')
//                {
//                    dp[i][j]=dp[i-1][j-1];
//                }
//                else if(p[j-1]=='*')
//                {
//                    if(dp[i][j]=dp[i][j-1]|dp[i-1][j])
//                    {
//                        begin_j=j+1;
//                        for(int loop_i=i+1;loop_i<=s_size;++loop_i)
//                        {
//                            dp[loop_i][j]=true;
//                        }
//                    };
//                }
//                else
//                {
//                    if(j>last_j&&j>i)
//                    {
//                        last_j=j;
//                        break;
//                    }
//                }
//                last_j=j;
//            }
//        }
//        return dp[s_size][p_size];
//    }
//};


//class Solution
//{
//public:
//    bool isMatch(string s, string p)
//    {
//        for (int i = 0; i + 1 < p.size();)
//        {
//            if (p[i] == '*' && p[i + 1] == '*')
//                p.erase(i, 1);
//            else ++i;
//        }
//        vector<bool> col(p.length() + 1, false);
//        vector<vector<bool>> dp(s.length() + 1, col);
//        const int s_size = s.length();
//        const int p_size = p.length();
//        dp[0][0] = true;
//        for (int i = 1; i <= p_size; ++i)
//        {
//            if (p[i-1] == '*')
//            {
//                dp[0][i] = true;
//            }
//            else break;
//        }
//        int begin_j = 1, last_j = 0, end_j = s_size;
//        char p_ele;
//        for (int i = 1; i <= p_size; ++i)
//        {
//            p_ele = p[i - 1];
//            begin_j = min(i, begin_j);
//            auto const  end_idx=min(end_j,s_size);
//            for (int j = begin_j; j <= end_idx; ++j)
//            {
//                if (dp[j - 1][i - 1]|dp[j-1][i]|dp[j][i - 1])
//                {
//                    if (s[j - 1] == p_ele || p_ele == '?')
//                    {
//                        if (dp[j][i] = dp[j - 1][i - 1])
//                        {
//                            end_j = j + 1;
//                        }
//                    }
//                    else if (p_ele == '*')
//                    {
//                        if (dp[j][i] = dp[j-1][i]|dp[j][i - 1])
//                        {
//                            for (int loop_j = j + 1; loop_j <= s_size; ++loop_j)
//                            {
//                                dp[loop_j][i] = true;
//                            }
//                            end_j = s_size;
//                            begin_j=j;
//                            break;
//                        };
//                    }
//                }
//            }
//        }
//        return dp[s_size][p_size];
//    }
//
//};

int main()
{
    Solution s;
   string  s="abcabczzzde",p="*abc???de*";
//    string s1 = "baa", s2 = "b?*";
//    string s1 = "ab", s2 = "*?*?*";
    std::cout << s.isMatch(s1, s2);
//array<bool,s1.length()> a;

    return 0;
}