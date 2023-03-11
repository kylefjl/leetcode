# 跳跃游戏

- 如果某一个作为起跳点的格子可以跳跃的距离是 3，那么表示后面 3 个格子都可以覆盖到
- 如果可以覆盖到所有的数字，说明end可以跳转到，反之，不可能跳转到

## 从末尾开始



```cc
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover=0;
        const int size=nums.size();//cover为可以跳转到的个数
        if(size<=1)return true;
        for (int i=size-2;i>=0;--i)//倒着查询，从size-2开始（不包括最后一个）
        {
            cover= (nums[i]+cover)>=(size-(i+1))?(size-(i+1)):cover;//倒着数，如果第i个数可以覆盖到i之后所有为覆盖的数，则更新cover为size-i-1
            if(size<=cover+1)return true;//如果cover覆盖了size-1个数（不包括最后一个），说明可以从front跳转到back;
        }
        return false;
        //return  canJump(nums.begin(),nums.end());//递归算法，会超时
    }
}
```

## 从头开始

- 可以对每一个能作为 起跳点 的格子都尝试跳一次，把能跳到最远的距离不断更新

- 如果可以一直跳到最后，说明可以覆盖到所有的数字