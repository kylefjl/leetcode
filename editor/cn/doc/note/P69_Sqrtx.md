# x 的平方根

## 二分法



```cc
  int mySqrt(unsigned int x) {

      return mySqrt(x,0,x);
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

```



## 牛顿迭代法

因为$error=Y-x^2$,$Y$为需要开根的数，代价函数的雅克比$J=-2x$,所以$\Delta x=- \dfrac {error}{J}$

>精度问题：因为x的初值给的是Y，所以得出的只有算术平方根，求要比真正的根大上$\epsilon(精度阈值)$

```cc
 class Solution {
public:
    int mySqrt( int x) {
        const  int Y=x;
        if(Y==0)return 0;//如果是0，直接返回
        return fabs(mySqrt_Newton(Y,Y ));//x*x=Y,x初值为Y
//        if(a*a>x) return a-1;
//        else return a;
//        return mySqrt(x,0,x);
    }
    double mySqrt_Newton(const int Y,double x)//x为需要开根号的数，a为初值
    {
        double delta_x=1;//步长给个初值，需要大于阈值
        while (fabs(delta_x)>1e-5)//步长小于阈值，不再迭代
        {
            delta_x=-(x*x-Y)/(2*x);//求delta_a ，牛顿迭代公式
            x+=delta_x;//更新
        }
        return x;
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
```

