# 柱状图中最大的矩形

## 单调栈

与接雨水类似，要点是找到构成矩形的条件

>找到了在i左边，从i-1，i-2到第一个小于`heights[i]`的位置[idx-1]，这样这idx和i两个位置间的柱高度都大于等于`heights[i]`，然后计算区域面积，计算完毕后对于这个区域外面两侧的部分来说,因为`heights[idx]`和 `heights[i]`的限制，矩形的最高高度就是`heights[i]`, 所以可以理解为这个区域里面的所有柱高度都变为了`heights[i]`

选择[单调栈]([单调栈 - OI Wiki (vicp.io)](http://magic.vicp.io/oi-wiki/ds/monotonous-stack/))的原因 

> 在一维数组中对每一个数找到第一个比自己小的元素。这类“在一维数组中找第一个满足某种条件的数”的场景就是典型的单调栈应用场景。

```cc
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
```



>执行耗时:116 ms,击败了89.45% 的C++用户
>内存消耗:73 MB,击败了99.07% 的C++用户