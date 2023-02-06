# 比特位计数

## 动态

对于所有的数字，只有两类：

奇数：二进制表示中，奇数一定比前面那个偶数多一个 1，因为多的就是最低位的 1。
 偶数：二进制表示中，偶数中 1 的个数一定和除以 2 之后的那个数一样多。因为最低位是 0，除以 2 就是右移一位，也就是把那个 0 抹掉而已，所以 1 的个数是不变的。
     

```cc
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>  result(n+1) ;
        for(int i = 0; i <=n; ++i){
            result[i] = result[i >> 1] + (i & 1);
        }
        return result;
    }
};
```



## 二进制运算 

不用历史信息，对每个数进行计算，不是这道题的最优解，但可以借鉴

[二进制中1的个数（分治法） - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/147862695)

```cc
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>  result(n+1) ;
        for(int i = 0; i <=n; ++i){
            result[i] = count(i);
        }
        return result;
    }
    inline int count (int  x){
        x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
        x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
        x = (x & 0x0000FFFF) + ((x >>16) & 0x0000FFFF);
        return x;
    }
};
```

