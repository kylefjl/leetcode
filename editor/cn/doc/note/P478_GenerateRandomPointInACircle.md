# 在圆内随机生成点

随机产生$\theta , r$,  要想随机产生在圆内的点， $\theta$ 为均匀分布，$r$为非均匀分布，**但$r^2$为均匀分布，**

可以从 $0, r^2$内随机再开平方，从而确保距离与面积比例一致。



```c++
class Solution {
public:
    Solution(double radius, double x_center, double y_center):uniform_dist_r(0,pow(radius,2)),uniform_dist_theta(0,2*M_PI),x_center( x_center),y_center(y_center)
    {
    }
    
    vector<double> randPoint() {

         r=sqrt(uniform_dist_r(e));//随机产生半径（非均匀分布）
         theta=uniform_dist_theta(e);//角度，均匀分布（0-2pai）
        return {x_center+r* sin(theta),y_center+r* cos(theta)};

    }
    double r,theta;
    const double x_center;
    const double y_center;
    std::mt19937 e{std::random_device{}()};//随机种子
    std::uniform_real_distribution<double> uniform_dist_r;//均匀随机分布
    std::uniform_real_distribution<double> uniform_dist_theta;
};
```

