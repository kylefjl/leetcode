//给定一个非空的字符串
// s ，检查是否可以通过由它的一个子串重复多次构成。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abab"
//输出: true
//解释: 可由子串 "ab" 重复两次构成。
// 
//
// 示例 2: 
//
// 
//输入: s = "aba"
//输出: false
// 
//
// 示例 3: 
//
// 
//输入: s = "abcabcabcabc"
//输出: true
//解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
// 
//
// 
//
// 提示： 
//
// 
// 
//
// 
// 1 <= s.length <= 10⁴ 
// s 由小写英文字母组成 
// 
//
// Related Topics 字符串 字符串匹配 👍 1145 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 重复的子字符串
* @author fjl
* @date 2024-03-04 17:19:47
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() <= 1){
            return false;
        }
        //将字符串s+s去掉首尾字符 保留中间的 用于kmp算法
        string str = s+s;
        str = str.substr(1,str.size()-2);//去掉首尾字符 保留中间的 用于kmp算法
        // 证明 s 是由一个子串重复多次构成的 当且仅当 s+s 中去掉首尾字符的字符串中包含 s
        // https://leetcode.cn/problems/repeated-substring-pattern/solutions/386481/zhong-fu-de-zi-zi-fu-chuan-by-leetcode-solution/
        return kmp(str,s);//kmp算法

    }
    //kmp算法 haystack为主串 needle为模式串  复杂度 O(n+m)
    int kmp(string  haystack,string  needle){

        vector<int> next(needle.size(),-1);
        getNext(needle,next);
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
                return 1;//返回匹配项的下标 从0开始 所以需要减去模式串的长度
            }
        }
        return 0;
    }
    // 复杂度 O(m)
    void getNext(string needle,vector<int> &next){
        for (int i = 1, j = -1; i <needle.size(); i++) {
            // 匹配不成功的话，j = next(j)
            while (j >=0 && needle[i] != needle[j+1]) j = next[j];
            // 匹配成功的话，先让 j++
            if (needle[i] == needle[j+1]) j++;
            // 更新 next[i]，结束本次循环，i++
            next[i] = j;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
//   s.repeatedSubstringPattern("abab");
   string needle="aaabaaab";
   vector <int> next(needle.size(),-1);
    s.getNext(needle,next);
    for (int i = 0; i < next.size(); ++i) {
        cout<<next[i]<<endl;
    }
   return 0;


}