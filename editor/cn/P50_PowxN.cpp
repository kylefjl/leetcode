//实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xⁿ ）。 
//
// 
//
// 示例 1： 
//
// 
//输入：x = 2.00000, n = 10
//输出：1024.00000
// 
//
// 示例 2： 
//
// 
//输入：x = 2.10000, n = 3
//输出：9.26100
// 
//
// 示例 3： 
//
// 
//输入：x = 2.00000, n = -2
//输出：0.25000
//解释：2-2 = 1/22 = 1/4 = 0.25
// 
//
// 
//
// 提示： 
//
// 
// -100.0 < x < 100.0 
// -231 <= n <= 231-1 
// n 是一个整数 
// -104 <= xⁿ <= 104 
// 
//
// Related Topics 递归 数学 👍 1136 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* Pow(x, n)
* @author name
* @date 2023-03-15 18:58:43
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double myPow(double x, int n) {
        unsigned int n_cur= fabs(n);//首先按正数计算
        double x_pow=1;//结果
        double x_port=x;//用来计算x^2 ,x^4,x^8.......
        //x^n=x^2 * x^4* x^8.......,比如x^10=x^2 * x^8；
        while(n_cur!=0)//如果计算n
        {
            if(n_cur&1){//如果最后一位为1，则说明当前的x^n分解成x_port再乘其他x_port;
                x_pow*=x_port;
            }
            x_port*=x_port;//计算x^2 ,x^4,x^8,.....
            n_cur=n_cur>>1;//移位
        }
        return n>0?x_pow:1/x_pow;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   cout<<s.myPow(2.0,10);
}