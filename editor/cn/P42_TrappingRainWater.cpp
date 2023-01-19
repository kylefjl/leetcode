//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
// 
//
// 示例 2： 
//
// 
//输入：height = [4,2,0,3,2,5]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// n == height.length 
// 1 <= n <= 2 * 10⁴ 
// 0 <= height[i] <= 10⁵ 
// 
//
// Related Topics栈 | 数组 | 双指针 | 动态规划 | 单调栈 
//
// 👍 4043, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//

#include<bits/stdc++.h>
using namespace std;

/*
* 接雨水
* @author name
* @date 2023-01-18 22:43:53
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int>& height) {
        int sum_height=0,no_water_height=0;//接完雨水的总高度和不接雨水的总高度
        pair<int,int> max={0,0};//第一个值为高度，第二个值为位置
        for(int i=0;i<height.size();++i)
        {
            if(height[i]>max.first)
            {//计算峰值左侧有雨水的总高度=间隔*较低的一边高度
                sum_height += (i - max.second) * max.first;
                max={height[i],i};
            }
            no_water_height+=height[i];
        }
        sum_height+=max.first;//加上峰值
        pair<int,int> max2={0,0};
        for(int i=height.size()-1;i>=(max.second-1)&&(i>=0);--i)
        {//从最右侧开始遍历，遍历到峰值或0退出
            if(height[i]>=max2.first)
            {//计算峰右侧有雨水的总高度=间隔*较低的一边高度
                sum_height += (max2.second-i) * max2.first;
                max2={height[i],i};
            }
        }//雨水的总高度=接完雨水的总高度-不接雨水的总高度
        return sum_height-no_water_height;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    vector<int> input={0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout<<s.trap(input)<<std::endl;
}