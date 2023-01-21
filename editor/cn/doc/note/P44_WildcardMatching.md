# 通配符匹配

# 动态规划

参考： [作者：nice-bardeeniyu](https://leetcode.cn/problems/wildcard-matching/solution/by-nice-bardeeniyu-22x4/)

$dp[i][j]$表示`s[0,...,i−1]`和`p[0,...,j−1]`能匹配，如果可以则为1，否则为0，`dp[i][j]`的值和`dp[i][j-1],dp[i-1][j],dp[i-1][j-1]` 有关，

- `s[]==p[]|p[]=='?'` 时, `dp[i][j]=dp[i-1][j-1]`;
- `p[]=='*'` 时, `dp[i][j]=dp[i][j-1] | dp[i-1][j])`;

示例：` s="abcabczzzde", p="*abc???de*";`


|       | start | *    | a    | b    | c    | ?    | ?    | ?    | d    | e    | *    |
| ----- | ----- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| start | 1     | 1    | 0    | 0    | 0    | 0    | 0    | 0    | 0    | 0    | 0    |
| a     | 0     | 1    | 1    | 0    | 0    | 0    | 0    | 0    | 0    | 0    | 0    |
| b     | 0     | 1    | 0    | 1    | 0    | 0    | 0    | 0    | 0    | 0    | 0    |
| c     | 0     | 1    | 0    | 0    | 1    | 0    | 0    | 0    | 0    | 0    | 0    |
| a     | 0     | 1    | 1    | 0    | 0    | 1    | 0    | 0    | 0    | 0    | 0    |
| b     | 0     | 1    | 0    | 1    | 0    | 0    | 1    | 0    | 0    | 0    | 0    |
| c     | 0     | 1    | 0    | 0    | 1    | 0    | 0    | 1    | 0    | 0    | 0    |
| z     | 0     | 1    | 0    | 0    | 0    | 1    | 0    | 0    | 0    | 0    | 0    |
| z     | 0     | 1    | 0    | 0    | 0    | 0    | 1    | 0    | 0    | 0    | 0    |
| z     | 0     | 1    | 0    | 0    | 0    | 0    | 0    | 1    | 0    | 0    | 0    |
| d     | 0     | 1    | 0    | 0    | 0    | 0    | 0    | 0    | 1    | 0    | 0    |
| e     | 0     | 1    | 0    | 0    | 0    | 0    | 0    | 0    | 0    | 1    | 1    |

未剪枝

```cc
class Solution {
public:
    bool isMatch(string s, string p) {
        for(int i=0;i+1<p.size();)
        {//去除连续的*
            if(p[i]=='*'&&p[i+1]=='*')   p.erase(i,1);
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
        {//p的第一个为*,则p[0,1]可以和空s匹配
            if(p[i]=='*')dp[0][i + 1] = true;
            else break;
        }
        for(int i=1;i<=s_size;++i)
        {
            for(int j=1;j<=p_size;++j)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')  dp[i][j]=dp[i][j-1]|dp[i-1][j];
            }
        }
        return dp[s_size][p_size];
    }
};
```



剪枝



```cc
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
```



剪枝后

>执行耗时:52 ms,击败了79.64% 的C++用户
>内存消耗:10.9 MB,击败了71.50% 的C++用户













