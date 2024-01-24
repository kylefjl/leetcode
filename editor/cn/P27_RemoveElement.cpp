//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。 
//
// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。 
//
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。 
//
// 
//
// 说明: 
//
// 为什么返回数值是整数，但输出的答案是数组呢? 
//
// 请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。 
//
// 你可以想象内部操作如下: 
//
// 
//// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
//int len = removeElement(nums, val);
//
//// 在函数里修改输入数组对于调用者是可见的。
//// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
//for (int i = 0; i < len; i++) {
//    print(nums[i]);
//}
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [3,2,2,3], val = 3
//输出：2, nums = [2,2]
//解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 
//nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1,2,2,3,0,4,2], val = 2
//输出：5, nums = [0,1,3,0,4]
//解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面
//的元素。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 100 
// 0 <= nums[i] <= 50 
// 0 <= val <= 100 
// 
//
// Related Topics 数组 双指针 👍 2130 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 移除元素
* @author fjl
* @date 2024-01-24 15:25:06
*/
//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    vector<int> nums={0,1,2,2,3,0,4,2};
//    vector<int> nums={3,2,2,3};

//   vector<int> nums={4,5};
    int val=2;
    cout<<s.removeElement(nums,val)<<"\n"<<endl;
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<endl;
    }
    return 0;


}