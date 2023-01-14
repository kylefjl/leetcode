//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。 
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 每个右括号都有一个对应的相同类型的左括号。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "()"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：s = "()[]{}"
//输出：true
// 
//
// 示例 3： 
//
// 
//输入：s = "(]"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10⁴ 
// s 仅由括号 '()[]{}' 组成 
// 
//
// Related Topics栈 | 字符串 
//
// 👍 3677, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//

#include<bits/stdc++.h>
using namespace std;

/*
* 有效的括号
* @author name
* @date 2023-01-14 14:05:56
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(const string& s) {
        string  str;
        for(auto item:s)//范围循环
        {
            if (item == '(' || item == '[' || item == '{')str.push_back(item);//入栈
            else//不是左括号，准备出栈
            {
                switch (item)
                {
                    case ')':
                        //有括号，出栈
                        if(str.back()=='(')str.pop_back();
                        else return false;//没有括号，返回false
                        break;
                    case ']':
                        if(str.back()=='[')str.pop_back();
                        else return false;
                        break;
                    case '}':
                        if(str.back()=='{')str.pop_back();
                        else return false;
                        break;
                    default:
                        break;
                }
            }
        }
        if(str.empty())return true;//全部出栈完毕，证明都有有效的括号
        else return false;//否则，有未匹配的括号，返回false
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   string str="({)}}[]";
   cout<<s.isValid(str)<<std::endl;
}
