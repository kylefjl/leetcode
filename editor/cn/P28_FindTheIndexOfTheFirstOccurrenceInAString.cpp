//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
//如果 needle 不是 haystack 的一部分，则返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//输入：haystack = "sadbutsad", needle = "sad"
//输出：0
//解释："sad" 在下标 0 和 6 处匹配。
//第一个匹配项的下标是 0 ，所以返回 0 。
// 
//
// 示例 2： 
//
// 
//输入：haystack = "leetcode", needle = "leeto"
//输出：-1
//解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= haystack.length, needle.length <= 10⁴ 
// haystack 和 needle 仅由小写英文字符组成 
// 
//
// Related Topics 双指针 字符串 字符串匹配 👍 2161 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 找出字符串中第一个匹配项的下标
* @author fjl
* @date 2024-03-04 12:11:36
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int strStr(string haystack, string needle) {
        //前缀表
        vector<int> next(needle.size(),-1);
        getNext(needle,next);
        return kmp(haystack,needle,next);
    }
    //kmp算法 haystack为主串 needle为模式串 next为前缀表 返回匹配项的下标 复杂度 O(n+m)
    int kmp(string&  haystack,string & needle,vector<int> &next){
        int j = 0;
        for (int i = 0; i < haystack.size(); ++i)//从前往后找
        {
            while (j>0 && needle[j] != haystack[i])//如果不匹配，回退 j=0时不需要回退 因为next[0] = -1 说明没有前缀 无法回退 此时需要 i++
            {
                j = next[j-1]+1 ;//回退到前缀表的值
            }
            if(needle[j] == haystack[i])//如果匹配
            { //执行次数 最多 n 次
                j++;//模式串的指针后移
            }
            if(j == needle.size())//如果匹配完了
            {
                return i-needle.size()+1;//返回匹配项的下标 从0开始 所以需要减去模式串的长度
            }
        }
        return -1;
    }
    // 复杂度 O(m^2)
    void getNext(string needle,vector<int> &next){
        for (int i = 0; i < needle.size(); ++i)//从前往后找
        {
            for (int k = needle.size()-1; k >i; --k)//从后往前找
            {
                if (needle[i] == needle[k]&&next[k-1]==(i-1))// 如果找到了相同的字符 且前一个字符的next值等于i-1 说明找到了一个前缀
                {
                    next[k] =next[k-1]+ 1;//前缀表的值等于前一个字符的next值加1
                }
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    cout<<s.strStr("aabaaabaaac","aabaaac")<<endl;
//    cout<<s.strStr("aabaabaafa","aabaaf")<<endl;
}