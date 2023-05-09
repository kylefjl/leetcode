# 统计圆内格点数目

## 枚举

```cc
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int result = 0;
        int max_x = 0,max_y=0,min_x=INT_MAX,min_y=INT_MAX;
        for (int i = 0; i < circles.size(); ++i)//找到枚举的范围，最大的x,y和最小的x,y
        {
            max_x=max(max_x,circles[i][0]+circles[i][2]);
            max_y=max(max_y,circles[i][1]+circles[i][2]);
            min_x=min(min_x,circles[i][0]-circles[i][2]);
            min_y=min(min_y,circles[i][1]-circles[i][2]);
        }
        for (int j = min_x; j <= max_x; ++j) {//枚举x,y
            for (int k = min_y; k <= max_y; ++k) {
                for (auto& circle : circles) {
                    int x = circle[0], y = circle[1], r = circle[2];//圆心坐标和半径平方
                    /* 圆心为(a,b) 半径为r的圆的方程为(x-a)²+(x-b)²=r² */
                    if ((j - x) * (j - x) + (k - y) * (k - y) <= r * r) {//如果在圆内，格点数目加一
                        result++;
                        break;
                    }
                }
            }
        }
        return result;
    }
};
```

