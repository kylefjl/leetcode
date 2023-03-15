# Pow(x, n)

## 快速幂 + 迭代

$x \times x^4 \times x^8 \times x^{64}$恰好等于 $x^{77}$ 。而这些指数部分又是什么呢？它们都是 2 的幂次，这是因为每个额外乘的 x 在之后都会被平方若干次。而这些指数 1，4，8 和 6464，恰好就对应了 7777 的二进制表示$(1001101)_2$中的每个 1！

```cc
class Solution {
public:
    double myPow(double x, int n) {
        unsigned int n_cur= fabs(n);//首先按正数计算
        double x_pow=1;//结果
        double x_port=x;//用来计算x^2 ,x^4,x^8.......
        //x^n=x^2 * x^4* x^8.......,比如x^10=x^2 * x^8；
        while(n_cur!=0)//如果计算n
        {
            if(n_cur&1){//如果最后一位为1，则说明当前的x^n可以分解成x_port再乘其他x_port;
                x_pow*=x_port;
            }
            x_port*=x_port;//计算x^2 ,x^4,x^8,.....
            n_cur=n_cur>>1;//移位
        }
        return n>0?x_pow:1/x_pow;//考虑负数的情况
    }
};
```



