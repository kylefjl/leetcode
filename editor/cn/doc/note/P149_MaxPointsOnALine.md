# 直线上最多的点数

思路及解法

我们可以考虑枚举所有的点，假设直线经过该点时，该直线所能经过的最多的点数。

假设我们当前枚举到点 i，如果直线同时经过另外两个不同的点 j 和 k，那么可以发现点 i 和点 j 所连直线的斜率恰等于点 ii 和点 k 所连直线的斜率。

于是我们可以统计其他所有点与点 i 所连直线的斜率，出现次数最多的斜率即为经过点数最多的直线的斜率，其经过的点数为该斜率出现的次数加一（点 i 自身也要被统计）。



## 哈希表记录斜率

https://leetcode.cn/problems/max-points-on-a-line/solution/zhi-xian-shang-zui-duo-de-dian-shu-by-le-tq8f/

浮点数类型可能因为精度不够而无法足够精确地表示每一个斜率，因此我们需要换一种方法来记录斜率。

一般情况下，斜率可以表示为 $\textit{slope} = \dfrac{\Delta y}{\Delta x}$的形式，因此我们可以用分子和分母组成的二元组来代表斜率。但注意到存在形如 $\dfrac{1}{2}=\dfrac{2}{4}$这样两个二元组不同，但实际上两分数的值相同的情况，所以我们需要将分数化简为最简分数的形式。

```cc
class Solution {
public:
    //求公约数  辗转相除法
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    int maxPoints(vector<vector<int>>& points) {
        const int n = points.size();
        if (n <= 2) return n;
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (ret >= n - i || ret > n / 2) {
                break;//剪枝 剩余的直线个数已经不可能超过现在的最大值
            }
            unordered_map<int, int> mp;//哈希
            for (int j = i + 1; j < n; ++j) {
                //用(x y)代表斜率y/x，为保证同一斜率对应唯一的(x,y),需要对
                //(x,y)进行约分且保证y为正值
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                if (x == 0) {
                    y = 1;
                } else if (y == 0) {
                    x = 1;
                } else {
                    if (y < 0) {
                        x = -x;
                        y = -y;
                    }
                    int gcdXY = gcd(abs(x), abs(y));
                    x /= gcdXY, y /= gcdXY;
                }
                mp[y + x * 20001]++;//保证y+x*20001作为key不会冲突
            }
            int maxn = 0;
            for (auto& [_, num] : mp) {
                maxn = max(maxn, num + 1);
            }
            ret = max(ret, maxn);
        }
        return ret;
    }
};
```

## 直接计数

用双精度浮点数类型提高精度

```cc
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int size = points.size(), result = 1;
        for (int i = 0; i < size - 1; ++i) {
            vector<double> ratio;//斜率
            for (int j = i + 1; j < size; ++j) {
                if (points[i][0] == points[j][0]) {
                    ratio.emplace_back(INT_MAX);//两点的x相当，确定的直线垂直，斜率为无穷大
                } else {//两点确定斜率
                    ratio.emplace_back((double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]));
                }
            }
            sort(ratio.begin(), ratio.end());//排序，方便对相同的斜率进行计数
            for (int j = 0; j < ratio.size(); ) {
                int index = j+1;
                while (index < ratio.size() && ratio[index] - ratio[j] < 2e-6) {
                    ++index;//如果在浮点型的误差范围之内，认为是同一斜率
                }
                result = max(result, index - j + 1);//计算最大的个数
                j=index;
            }
        }
        return result;
    }
};

```













