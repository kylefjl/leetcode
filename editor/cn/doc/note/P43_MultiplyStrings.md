# 字符串相乘

## karatsuba乘法

基本思路如下(分而治之)

设：`num1=a*10^n+b;n=length/2` `num2=c*10^n+d;n=length/2;`

则`num1*num2=a*c*10^(2n)+((a+b)(c+d)-a*c-b*d)*10^n+b*d;`，这样就可以把乘法展开成小数乘法，并且比`(a*10^n+b)*(c*10^n+d)`的展开少一次乘法运算，对计算机更友好

>代码太长，就不放在这里了，可以看cpp文件，因为写的有些混乱，结果性能也没有比普通的竖乘快，就不多说了



## 竖乘

官方代码

```cc
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ans = "0";
        int m = num1.size(), n = num2.size();
        for (int i = n - 1; i >= 0; i--) {
            string curr;
            int add = 0;
            for (int j = n - 1; j > i; j--) {
                curr.push_back(0);
            }
            int y = num2.at(i) - '0';
            for (int j = m - 1; j >= 0; j--) {
                int x = num1.at(j) - '0';
                int product = x * y + add;
                curr.push_back(product % 10);
                add = product / 10;
            }
            while (add != 0) {
                curr.push_back(add % 10);
                add /= 10;
            }
            reverse(curr.begin(), curr.end());
            for (auto &c : curr) {
                c += '0';
            }
            ans = addStrings(ans, curr);
        }
        return ans;
    }

    string addStrings(string &num1, string &num2) {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string ans;
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            int result = x + y + add;
            ans.push_back(result % 10);
            add = result / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        for (auto &c: ans) {
            c += '0';
        }
        return ans;
    }
};

```

