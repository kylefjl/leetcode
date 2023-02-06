//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。 
//
// 求在该柱状图中，能够勾勒出来的矩形的最大面积。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入：heights = [2,1,5,6,2,3]
//输出：10
//解释：最大的矩形为图中红色区域，面积为 10
// 
//
// 示例 2： 
//
// 
//
// 
//输入： heights = [2,4]
//输出： 4 
//
// 
//
// 提示： 
//
// 
// 1 <= heights.length <=10⁵ 
// 0 <= heights[i] <= 10⁴ 
// 
//
// Related Topics 栈 数组 单调栈 👍 2305 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 柱状图中最大的矩形
* @author fjl
* @date 2023-02-06 11:12:54
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.emplace_back(0);//哨兵
        const int  lenght=heights.size();
        int rectArea=0,idx=0,temp_area;
        std::stack<int> h_list;//单调栈，不直接存放高度值，而是存放heights中高度的序列号
        h_list.emplace(0);//先加入一个头数据，因为添加了哨兵，所以不用考虑为空的情况
        for (int i = 0; i <lenght ; ++i)
        {
            if(heights[h_list.top()]<heights[i])//比栈顶大，直接入栈
            {
                h_list.push(i);
            }
            else if (heights[h_list.top()]>heights[i])//比栈顶小，依次弹出并计算区域，然后入栈
            {
                do
                {
                    idx=h_list.top();//存放弹出的序列号
                    temp_area=(i-idx)*heights[idx];//计算矩形区域
                    rectArea= temp_area>rectArea?temp_area:rectArea;//更新
                    h_list.pop();//弹出
                } while ((!h_list.empty())&& heights[h_list.top()]>heights[i]);//非空且需要插入的还比栈顶小，接着弹出
                //找到了在i左边，从左往右第一个大于heights[i]的位置，这两个位置间的矩形区域已经计算过了，而且对于这个区域外面两侧的部分来说,
                // 因为heights[idx]和 heights[i]的限制，矩形的最高高度就是heights[i], 所以改写heights[idx]高度并再次入栈
                heights[idx]=heights[i];
                h_list.push(idx);//再次入栈
            }
        }
        return rectArea;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   vector<int> input={4,2,0,3,2,5};
   cout<< s.largestRectangleArea(input);
}