//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。 
//
// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "anagram", t = "nagaram"
//输出: true
// 
//
// 示例 2: 
//
// 
//输入: s = "rat", t = "car"
//输出: false 
//
// 
//
// 提示: 
//
// 
// 1 <= s.length, t.length <= 5 * 10⁴ 
// s 和 t 仅包含小写字母 
// 
//
// 
//
// 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？ 
//
// Related Topics 哈希表 字符串 排序 👍 894 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 有效的字母异位词
* @author fjl
* @date 2024-02-28 16:07:20
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length())return false;
        int str_count[26];//数组 哈希
        for(auto & ch:s)//遍历字符串
        {
            ++str_count[ch-'a'];//统计每个字符出现的次数
        }
        for(auto & ch:t)
        {
            --str_count[ch-'a'];//减去t中每个字符出现的次数
        }
        for(int i : str_count)//如果计数表中有不为0 返回false
        {
            if(i!=0)return false;
        }
        return true;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
}