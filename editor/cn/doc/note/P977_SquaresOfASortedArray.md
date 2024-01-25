# 有序数组的平方



双指针

```c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        int size= nums.size();
        int negative = -1;
        //找到第一个负数的位置
        for (int i = 0; i < size; ++i) {
            if (nums[i] < 0) {
                negative = i;
            }
            nums[i] = nums[i] * nums[i];//平方
        }

        int i = negative, j = negative + 1, index = 0;//i指向负数,j指向正数
        while(i>=0&&j<size)
        {
            if (nums[i]>nums[j])//负数大于正数,则正数先放入结果数组
            {
                result[index]=nums[j];
                index++;
                j++;//正数从前往后遍历
            }
            else//负数小于正数,则负数先放入结果数组
            {
                result[index]=nums[i];
                index++;
                i--;//负数从后往前遍历
            }
        }
        while (i>=0) result[index]=nums[i],index++,i--;//负数还有剩余 从后往前遍历放入结果数组
        while (j<size)  result[index]=nums[j],index++,j++;//正数还有剩余 从前往后遍历放入结果数组
        return result;
    }
};
```

