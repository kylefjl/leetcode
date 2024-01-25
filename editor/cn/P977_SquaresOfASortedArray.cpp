//给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。 
//
// 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-4,-1,0,3,10]
//输出：[0,1,9,16,100]
//解释：平方后，数组变为 [16,1,0,9,100]
//排序后，数组变为 [0,1,9,16,100] 
//
// 示例 2： 
//
// 
//输入：nums = [-7,-3,2,3,11]
//输出：[4,9,9,49,121]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// nums 已按 非递减顺序 排序 
// 
//
// 
//
// 进阶： 
//
// 
// 请你设计时间复杂度为 O(n) 的算法解决本问题 
// 
//
// Related Topics 数组 双指针 排序 👍 955 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 有序数组的平方
* @author fjl
* @date 2024-01-25 16:16:43
*/
//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    vector<int> nums={-4,-1,0,3,10};
    auto result=s.sortedSquares(nums);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<" ";
    }
    return 0;
}