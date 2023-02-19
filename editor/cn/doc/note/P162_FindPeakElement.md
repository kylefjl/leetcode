# 寻找峰值

要求log(n)的复杂度，使用二分查找

[关于能够二分的两点证明](https://leetcode.cn/problems/find-peak-element/solution/gong-shui-san-xie-noxiang-xin-ke-xue-xi-qva7v/)

关注 TA

```cc
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if( nums.end()-nums.begin()<2)return 0;//如果只有1个数或数组未空，直接返回0；
        if(nums[0]>nums[1])return 0;//如果第一个数比第二个数大，则第一个数就是峰值(默认边界为负无穷)
        else if(*(nums.end()-1)>*(nums.end()-2))
        {//如果最后一个数比倒数第二个数大，则最后一个数就是峰值(默认边界为负无穷)
            return nums.end()- nums.begin()-1;
        }//如果第一个数比第二个数大，则第一个数就是峰值(默认边界为负无穷)
        //二分查找峰值，需要保证beg-1和end1为有效数据的迭代器
        return findPeakBinary(nums.begin()+1,nums.end()-1)-nums.begin();
    }
    //二分查找峰值，需要保证beg-1和end1为有效数据的迭代器，防止越界访问
    vector<int>::iterator findPeakBinary(vector<int>::iterator beg1, vector<int>::iterator end1){
        auto peak= experimental::randint(0, (int)(end1 - beg1) - 1) + beg1;//随机取
        if(*peak>*(peak-1)&&*peak>*(peak+1))//峰值
        {
            return peak;
        }
        else if(*peak<*(peak-1))//下坡，把peak作为右边界的哨兵
        {
            return findPeakBinary(beg1, peak);
        }
        else//上坡，把peak+1作为左边界
        {
            return findPeakBinary(peak+1, end1);
        }
    }
};
```

> 执行耗时:4 ms,击败了72.56% 的C++用户
> 内存消耗:8.7 MB,击败了8.64% 的C++用户