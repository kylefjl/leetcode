//给你一个非负整数 x ，计算并返回 x 的 算术平方根 。 
//
// 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。 
//
// 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。 
//
// 
//
// 示例 1： 
//
// 
//输入：x = 4
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：x = 8
//输出：2
//解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= x <= 2³¹ - 1 
// 
//
// Related Topics 数学 二分查找 👍 1285 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* x 的平方根 
* @author name
* @date 2023-03-15 12:14:53
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mySqrt(unsigned int x) {
        if(x==0)return 0;//如果是0，直接返回
        return fabs(mySqrt_Newton(x,x ));//a*a=x,初值给x
//        if(a*a>x) return a-1;
//        else return a;
//        return mySqrt(x,0,x);
    }
    double mySqrt_Newton(unsigned int x,double a)//x为需要开根号的数，min max为解的范围，供迭代使用
    {
        double delta_a=1;//给个初值，需要大于阈值
        while (fabs(delta_a)>1e-5)//步长小于阈值，不再迭代
        {
            delta_a=-(a*a-x)/(2*a);//求delta—a ，牛顿迭代公式
            a+=delta_a;//更新
        }
        return a;
    }

    unsigned long int mySqrt(unsigned long int x,unsigned long int  min,unsigned long int max)//x为需要开根号的数，min max为解的范围，供迭代使用
    {
        unsigned long int a=round(0.5*(min+max));//二分选取点
        if((a*a<x&&(a+1)*(a+1)>x)||a*a==x)return a;
        else if(a*a>x)return mySqrt(x,min,a);//更新解的范围
        else if(a*a<x)return mySqrt(x,a,max);
        else return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   cout<<s.mySqrt(505553488);
}