//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。 
//
// 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。 
//
// 
//
// 示例 1: 
//
// 
//输入: num1 = "2", num2 = "3"
//输出: "6" 
//
// 示例 2: 
//
// 
//输入: num1 = "123", num2 = "456"
//输出: "56088" 
//
// 
//
// 提示： 
//
// 
// 1 <= num1.length, num2.length <= 200 
// num1 和 num2 只能由数字组成。 
// num1 和 num2 都不包含任何前导零，除了数字0本身。 
// 
//
// Related Topics数学 | 字符串 | 模拟 
//
// 👍 1125, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//

#include<bits/stdc++.h>

using namespace std;

/*
* 字符串相乘
* @author name
* @date 2023-01-19 11:14:04
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        auto result = multiply2(num1, num2);
        for (int i = 0; i < result.length(); ++i)//去除前导0
        {
            if (result[i] != '0')return result.substr(i, result.length() - i);
        }
        return "0";
    }

    string multiply2(string num1, string num2)
    {

        if (num1.length() + num2.length() < 19)//用普通乘法算
        {
            unsigned long long a = 0, b = 0;
            for (auto item: num1)
            {
                a = a * 10 + (item - '0');
            }
            for (auto item: num2)
            {
                b = b * 10 + (item - '0');
            }
            return std::to_string(a * b);
        }
        if (num1.length() < 10)
        {
            unsigned long long  a = 0;
            for (auto item: num1)
            {
                a = a * 10 + (item - '0');
            }
            return multiply(a, num2);//对num2继续进行大数相乘
        }
        else if (num2.length() < 10)
        {
            unsigned long long  a = 0;
            for (auto item: num2)
            {
                a = a * 10 + (item - '0');
            }
            return multiply(num1, a);
        }
        else
        {
            //补齐，方便分割
            if (num1.length() > num2.length())num2 = string(num1.length() - num2.length(), '0') + num2;
            if (num1.length() < num2.length())num1 = string(num2.length() - num1.length(), '0') + num1;
            string a = num1.substr(0, num1.length() / 2);//num1=a*10^n+b;n=length/2;
            string b = num1.substr(num1.length() / 2, num1.length() - num1.length() / 2);
            string c = num2.substr(0, num2.length() / 2);//num2=c*10^n+d;n=length/2;
            string d = num2.substr(num2.length() / 2, num2.length() - num2.length() / 2);
            string a_c = multiply2(a, c);
            string b_d = multiply2(b, d);
            string ab_cd = multiply2(bigNumAdd(a, b), bigNumAdd(c, d));
            string bc_ad = bigNumSub(bigNumSub(ab_cd, a_c), b_d);
            bc_ad = bc_ad + string(b.length(), '0');
            a_c = a_c + string(b.length() + d.length(), '0');
            //num1*num2=a*c*10^(2n)+((a+b)(c+d)-a*c-b*d)*10^n+b*d;
            return bigNumAdd(bigNumAdd(a_c, b_d), bc_ad);
        };
    }
//大数相加，没有去除前导0
    string bigNumAdd( string str1,  string str2)
    {
           string result(max(str1.length(), str2.length()) + 1, '0');
        if (str1.length() > str2.length())str2 = string(str1.length() - str2.length(), '0') + str2;
        if (str1.length() < str2.length())str1 = string(str2.length() - str1.length(), '0') + str1;
        int i = str1.length() - 1, temp = 0;
        for (; i >= 0; --i)
        {
            temp = str1[i] + str2[i] + result[i + 1] - 3 * '0';
            result[i + 1] = static_cast<char>(temp % 10 + '0');
            result[i] = static_cast<char>(temp / 10 + '0');
        }
        if (result[0] == '0')return result.substr(1, result.length() - 1);
        else return result;

    }
//大数相减
    string bigNumSub( string str1,  string str2)
    {
        string result(max(str1.length(), str2.length()) + 1, '0');
        if (str1.length() > str2.length())str2 = string(str1.length() - str2.length(), '0') + str2;
        if (str1.length() < str2.length())str1 = string(str2.length() - str1.length(), '0') + str1;
        int i = str1.length() - 1, temp = 0;
        for (; i >= 0; --i)
        {
            temp = str1[i] - str2[i] + result[i + 1] - '0';
            if (temp < 0)
            {
                result[i + 1] = static_cast<char>(10 + temp + '0');
                result[i] = static_cast<char>(-1 + '0');
            }
            else
            {
                result[i + 1] = static_cast<char>(temp + '0');
            }

        }
        if (result[0] == '0')return result.substr(1, result.length() - 1);
        else return result;
    }
//重载，unsigned long long 乘以大数
    string multiply(unsigned long long num1, string num2)
    {
        if (num2.length() < 10)
        {
            unsigned long long b = 0;
            for (auto item: num2)
            {
                b = b * 10 + (item - '0');
            }
            return std::to_string(num1 * b);
        }
        else
        {
            string c = num2.substr(0, num2.length() / 2);
            string d = num2.substr(num2.length() / 2, num2.length() - num2.length() / 2);
            string num_c = multiply(num1, c);
            string num_d = multiply(num1, d);
            num_c = num_c + string(d.length(), '0');
            return bigNumAdd(num_c, num_d);
        }
    }
//重载，unsigned long long 乘以大数
    string multiply(string num1, unsigned long long num2)
    {
        if (num1.length() < 10)
        {
            unsigned long long b = 0;
            for (auto item: num1)
            {
                b = b * 10 + (item - '0');
            }
            return std::to_string(num2 * b);
        }
        else
        {
            string c = num1.substr(0, num1.length() / 2);
            string d = num1.substr(num1.length() / 2, num1.length() - num1.length() / 2);
            string num_c = multiply(c, num2);
            string num_d = multiply(d, num2);
            num_c = num_c + string(d.length(), '0');
            return bigNumAdd(num_c, num_d);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    string str1 = "930047927929", str2 = "7607999646288178";//7075804306714884864908723362


    std::cout << s.multiply(str1, str2) << std::endl;
}