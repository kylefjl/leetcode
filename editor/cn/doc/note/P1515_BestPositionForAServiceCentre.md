# 服务中心的最佳位置

## 梯度下降法

参考 https://leetcode.cn/problems/best-position-for-a-service-centre/solution/fu-wu-zhong-xin-de-zui-jia-wei-zhi-by-leetcode-sol/

对于给定的点 (x, y)，它的梯度方向是函数值上升最快的方向，因此梯度反向就是函数值下降最快的方向

优化的函数为：

$f(x_c,y_c)=\sum^{n-1}_{i=0}\sqrt{(x_c-x_i)^2+(y_c-y_i)^2}$

它的导数为：
$$
\begin{cases}
\dfrac{\delta f}{\delta x}=\sum\limits_{i=0}^{n-1}\dfrac{x_c-x_i}{\sqrt{(x_c-x_i)^2+(y_c-y_i)^2}}\\
\dfrac{\delta f}{\delta y}=\sum\limits_{i=0}^{n-1}\dfrac{y_c-y_i}{\sqrt{(x_c-x_i)^2+(y_c-y_i)^2}}
\end{cases}
$$
那么梯度反向$-\nabla f=(-\dfrac{\delta f}{\delta x},-\dfrac{\delta f}{\delta y})$，我们从一个初始点（x,y）开始进行迭代，每次令
$$
\begin{cases}x_{start}'=x_{start}'-\alpha\dfrac{\delta f}{\delta x}\\y_{start}'=y_{start}'-\alpha\dfrac{\delta f}{\delta y}\end{cases}
$$
得到一个新的点 $(x_{start}', y'_{start})$，其中α 为学习率（learning rate）。当迭代了一定次数之后，当前的点会非常接近真正的最小值点，如果我们的学习速率保持不变，迭代的结果将会在最小值点的周围来回「震荡」，无法继续接近最小值点。因此，我们需要设置学习率衰减（learning rate decay），在迭代的过程中逐步减小学习率，向最小值点逼近。

在下面的代码中，我们令：

- 初始点  $(x_{start}, y_{start})$等于所有点的算术平均值；

- 学习率α=1；

- 学习率衰减=η=$10^{-3}$

- 当 $(x_{start}, y_{start})$与  $(x_{start}', y'_{start})$的距离小于 $10^{-7}$ 时结束迭代。

```cc
#define DIS(x,y,x0,y0) sqrt(pow(x-x0,2)+pow(y-y0,2))
class Solution {
public:
    // 获得到postions中所有点的距离和最小的点 采用梯度下降法
    double getMinDistSum(vector<vector<int>>& positions) {
        double x=0,y=0;//x,y为中心点的坐标
        double alpha=1;//学习率
        double decay=1e-3;//衰减系数
        for (auto &position:positions) {//初始化中心点（x，y的平均值）
            x+=position[0];
            y+=position[1];
        }
        x=x/positions.size();//求平均值
        y=y/positions.size();//求平均值
        auto getDist =[&](double x, double y) {//求到所有点的距离和
            double dis = 0;
            for (auto &position:positions) {
                dis += sqrt(pow(position[0] - x, 2) + pow(position[1] - y, 2));//求距离
            }
            return dis;
        };
        while (true)
        {
            double dx=0,dy=0;
            for (auto &position:positions) {//求梯度
                dx+=(x-position[0])/(DIS(x,y,position[0],position[1])+1e-7);//加1e-7  防止除0
                dy+=(y-position[1])/(DIS(x,y,position[0],position[1])+1e-7);
            }
            dx=alpha*dx;//乘以学习率
            dy=alpha*dy;//乘以学习率
            x-=dx;//更新中心点
            y-=dy;
            alpha*=(1-decay);//学习率衰减
            if(DIS(dx,dy,0,0)<1e-6)//当梯度足够小的时候，认为找到最优值，退出循环
                break;
        }
        return getDist(x,y);//返回最到所有点的距离和的最小值
    }
};
```

