<p>给定一个字符串&nbsp;(<code>s</code>) 和一个字符模式&nbsp;(<code>p</code>) ，实现一个支持&nbsp;<code>'?'</code>&nbsp;和&nbsp;<code>'*'</code>&nbsp;的通配符匹配。</p>

<pre>'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
</pre>

<p>两个字符串<strong>完全匹配</strong>才算匹配成功。</p>

<p><strong>说明:</strong></p>

<ul> 
 <li><code>s</code>&nbsp;可能为空，且只包含从&nbsp;<code>a-z</code>&nbsp;的小写字母。</li> 
 <li><code>p</code>&nbsp;可能为空，且只包含从&nbsp;<code>a-z</code>&nbsp;的小写字母，以及字符&nbsp;<code>?</code>&nbsp;和&nbsp;<code>*</code>。</li> 
</ul>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong>
s = "aa"
p = "a"
<strong>输出:</strong> false
<strong>解释:</strong> "a" 无法匹配 "aa" 整个字符串。</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong>
s = "aa"
p = "*"
<strong>输出:</strong> true
<strong>解释:</strong>&nbsp;'*' 可以匹配任意字符串。
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre><strong>输入:</strong>
s = "cb"
p = "?a"
<strong>输出:</strong> false
<strong>解释:</strong>&nbsp;'?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
</pre>

<p><strong>示例&nbsp;4:</strong></p>

<pre><strong>输入:</strong>
s = "adceb"
p = "*a*b"
<strong>输出:</strong> true
<strong>解释:</strong>&nbsp;第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
</pre>

<p><strong>示例&nbsp;5:</strong></p>

<pre><strong>输入:</strong>
s = "acdcb"
p = "a*c?b"
<strong>输出:</strong> false</pre>

<details><summary><strong>Related Topics</strong></summary>贪心 | 递归 | 字符串 | 动态规划</details><br>

<div>👍 983, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/discussions/939' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://mp.weixin.qq.com/s/NF8mmVyXVfC1ehdMOsO7Cw' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.github.io/algo/images/others/%E5%85%A8%E5%AE%B6%E6%A1%B6.jpg' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：[数据结构精品课](https://aep.h5.xeknow.com/s/1XJHEO) 已更新到 V2.1，[手把手刷二叉树系列课程](https://aep.xet.tech/s/3YGcq3) 上线。**

<details><summary><strong>labuladong 思路</strong></summary>

## 基本思路

这道题和 [10. 正则表达式匹配](/problems/regular-expression-matching) 几乎一样，这里的 `?` 通配符就是第 10 题的 `.`，这里的 `*` 就是第 10 题的 `.?` 组合，所以一个投机取巧的解法就是把本题中的通配符转化成第 10 题的形式，然后直接套用第 10 题的解法。

如果不投机取巧，照着第 10 题的解法逻辑也可以写出本题的解法，唯一需要注意的是本题的测试用例可能出现很多 `*` 连续出现的情况，很容易看出**连续多个 `*` 和一个 `*` 的通配效果是一样的**，所以我们可以提前删除连续的 `*` 以便提升一些效率。

**标签：[动态规划](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzAxODQxMDM0Mw==&action=getalbum&album_id=1318881141113536512)**

## 解法代码

```cpp
class Solution {
    public:
    // 备忘录，-1 代表还未计算，0 代表 false，1 代表 true
    vector<vector<int>> memo;

    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        // 将 p 中相邻的 * 去除，以提升效率
        string pp = remove_adj_star(p);
        int m = s.size(), n = pp.size();
        // 备忘录初始化为 -1
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        // 执行自顶向下带备忘录的动态规划
        return dp(s, 0, pp, 0);
    }

    // 删除相邻的 * 号，返回删除后的字符
    string remove_adj_star(string p) {
        if (p.empty()) {
            return "";
        }
        string pp;
        pp.push_back(p[0]);
        for (int i = 1; i < p.size(); i++) {
            if (p[i] == '*' && p[i - 1] == '*') {
                continue;
            }
            pp.push_back(p[i]);
        }
        return pp;
    }

    // 定义：判断 s[i..] 是否能被 p[j..] 匹配
    bool dp(string& s, int i, string& p, int j) {
        // base case
        if (j == p.size() && i == s.size()) {
            return true;
        }
        if (i == s.size()) {
            for (int k = j; k < p.size(); k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (j == p.size()) {
            return false;
        }
        if (memo[i][j] != -1) {
            return bool(memo[i][j]);
        }

        bool res = false;
        if (s[i] == p[j] || p[j] == '?') {
            // s[i] 和 p[j] 完成匹配
            res = dp(s, i + 1, p, j + 1);
        } else if (p[j] == '*') {
            // s[i] 和 p[j] 不匹配，但 p[j] 是通配符 *
            // 可以匹配 0 个或多个 s 中的字符，
            // 只要有一种情况能够完成匹配即可
            res = dp(s, i + 1, p, j)
                    || dp(s, i, p, j + 1);
        }
        // 将 s[i] 和 p[j] 的匹配结果存储备忘录
        memo[i][j] = res;

        return res;
    }
};
```

</details>
</div>



