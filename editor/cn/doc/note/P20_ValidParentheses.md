# 有效的括号

要点是栈，利用string提供的入栈出栈操作速度就很快

```cc
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
```

> 执行耗时:0 ms,击败了100.00% 的C++用户
> 内存消耗:6 MB,击败了97.88% 的C++用户