# 接雨水

主要思路是利用公式：雨水的总高度=接完雨水的总高度-不接雨水的总高度，然后计算接完雨水的总高度时以最高的一个为中心，分为左右两边计算，对每一个可能接到水的区间：接完雨水的总高度=间隔*较低的一边高度

```cc
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
```

>执行耗时:12 ms,击败了81.23% 的C++用户
>内存消耗:19.1 MB,击败了96.21% 的C++用户





