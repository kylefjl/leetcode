# 移除元素

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return removeElement_ptr_pro(nums,val);
    }
    // 快慢双指针法，同时判断快指针和慢指针的值，减少交换的次数
    int removeElement_ptr_pro(vector<int>& nums, int val) {
        int size = nums.size();
        int slow = 0, fast = 1;
        while(fast<size)
        {
            while(fast<size&&(nums[fast]==val||slow==fast))fast++;// 当快指针的值等于val或者快慢指针相等时，快指针向后移动一位
            while(slow<fast&&nums[slow]!=val)slow++;// 当慢指针的值不等于val时，慢指针向后移动一位,直到慢指针的值等于val或者慢指针和快指针相等
            if(fast>=size)break;// 如果快指针已经到达数组的末尾，那么就退出循环
            if(nums[slow]==val&&nums[fast]!=val)// 如果慢指针的值等于val，快指针的值不等于val，那么就交换快慢指针的值
            {
                nums[slow++]=nums[fast];
                nums[fast++]=val;
            }
        }
        while(slow<size&&nums[slow]!=val)slow++;// 当快指针到达数组的末尾时，慢指针继续向后移动，直到慢指针的值等于val，此时慢指针的之前的数就是想要的数组
        return  slow;
    }
    // 快慢双指针法，只判断快指针的值，会产生较大量的交换
    int removeElement_ptr(vector<int>& nums, int val) {
        int size = nums.size();
        int slow = 0, fast = 0;
        while(fast<size)
        {
            if(nums[fast]!=val)// 当快指针的值不等于val时
            {
                nums[slow++]=nums[fast++];// 将快指针的值赋值给慢指针，然后快慢指针同时向后移动一位
            }
        }
        return slow;
    }

};
```

