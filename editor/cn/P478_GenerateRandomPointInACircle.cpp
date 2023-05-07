//给定圆的半径和圆心的位置，实现函数 randPoint ，在圆中产生均匀随机点。 
//
// 实现 Solution 类: 
//
// 
// Solution(double radius, double x_center, double y_center) 用圆的半径 radius 和圆心的位置
// (x_center, y_center) 初始化对象 
// randPoint() 返回圆内的一个随机点。圆周上的一点被认为在圆内。答案作为数组返回 [x, y] 。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入: 
//["Solution","randPoint","randPoint","randPoint"]
//[[1.0, 0.0, 0.0], [], [], []]
//输出: [null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]
//解释:
//Solution solution = new Solution(1.0, 0.0, 0.0);
//solution.randPoint ();//返回[-0.02493，-0.38077]
//solution.randPoint ();//返回[0.82314,0.38945]
//solution.randPoint ();//返回[0.36572,0.17248] 
//
// 
//
// 提示： 
//
// 
// 0 < radius <= 10⁸ 
// -10⁷ <= x_center, y_center <= 10⁷ 
// randPoint 最多被调用 3 * 10⁴ 次 
// 
//
// Related Topics 几何 数学 拒绝采样 随机化 👍 161 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 在圆内随机生成点
* @author name
* @date 2023-05-07 21:02:57
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    Solution(double radius, double x_center, double y_center):uniform_dist_r(0,pow(radius,2)),uniform_dist_theta(0,2*M_PI),x_center( x_center),y_center(y_center)
    {
    }
    
    vector<double> randPoint() {

         r=sqrt(uniform_dist_r(e));//随机产生半径（非均匀分布），r的平方是均匀分布
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

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
//   Solutionv

}