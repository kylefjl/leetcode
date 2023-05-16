//给你一个二维整数数组 circles ，其中 circles[i] = [xi, yi, ri] 表示网格上圆心为 (xi, yi) 且半径为 ri 的第 
//i 个圆，返回出现在 至少一个 圆内的 格点数目 。 
//
// 注意： 
//
// 
// 格点 是指整数坐标对应的点。 
// 圆周上的点 也被视为出现在圆内的点。 
// 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：circles = [[2,2,1]]
//输出：5
//解释：
//给定的圆如上图所示。
//出现在圆内的格点为 (1, 2)、(2, 1)、(2, 2)、(2, 3) 和 (3, 2)，在图中用绿色标识。
//像 (1, 1) 和 (1, 3) 这样用红色标识的点，并未出现在圆内。
//因此，出现在至少一个圆内的格点数目是 5 。 
//
// 示例 2： 
//
// 
//
// 
//输入：circles = [[2,2,2],[3,4,1]]
//输出：16
//解释：
//给定的圆如上图所示。
//共有 16 个格点出现在至少一个圆内。
//其中部分点的坐标是 (0, 2)、(2, 0)、(2, 4)、(3, 2) 和 (4, 4) 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= circles.length <= 200 
// circles[i].length == 3 
// 1 <= xi, yi <= 100 
// 1 <= ri <= min(xi, yi) 
// 
//
// Related Topics 几何 数组 哈希表 数学 枚举 👍 15 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 统计圆内格点数目
* @author name
* @date 2023-05-09 15:01:43
*/
//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   vector<int> result,x;
//    for (int i = 0; i < 1000; ++i)
//    {
//        result.push_back(s.countLatticePoints({{0,0,i}}));
//    x.push_back(i);
//    }
//    vector<double> rate;
//    for (int i = 0; i < 1000; ++i)
//    {
//        rate.push_back(static_cast<double>(result[i])/(i*i));
//    }





}