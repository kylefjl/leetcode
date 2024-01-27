//给定一个含有 n 个正整数的数组和一个正整数 target 。 
//
// 找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返
//回其长度。如果不存在符合条件的子数组，返回 0 。 
//
// 
//
// 示例 1： 
//
// 
//输入：target = 7, nums = [2,3,1,2,4,3]
//输出：2
//解释：子数组 [4,3] 是该条件下的长度最小的子数组。
// 
//
// 示例 2： 
//
// 
//输入：target = 4, nums = [1,4,4]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：target = 11, nums = [1,1,1,1,1,1,1,1]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= target <= 10⁹ 
// 1 <= nums.length <= 10⁵ 
// 1 <= nums[i] <= 10⁵ 
// 
//
// 
//
// 进阶： 
//
// 
// 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。 
// 
//
// Related Topics 数组 二分查找 前缀和 滑动窗口 👍 2035 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 长度最小的子数组
* @author fjl
* @date 2024-01-27 18:16:04
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //前缀和
        const int size = nums.size();
        vector<int> sums(size+1,0);
        for (int i = 1; i <= size; ++i) {
            sums[i] = sums[i-1] + nums[i-1];
        }
        int ans = size;
        int length=ans;
        bool length_update=false;
        if (sums[size]< target) return 0;//如果所有元素的和都小于target，直接返回0
        for (int i = 0; i < size; ++i)
        {
            while(length>=0) //找到一个length，使得i+length满足条件且length最小
            {
                if (i+length>size)length=size-i;//如果i+length>size，说明后面的元素不够了，直接取到最后一个元素
                if(sums[length+i]-sums[i]>=target)//如果此时的长度满足条件，就减少长度，继续判断，直到不满足条件
                {
                    length_update=true;//记录是否减过长度
                    length--;
                }
                else break;//如果已经不满足条件，就跳出循环
            }
            if(length_update)ans=(length+1);//如果length_update为true，说明减过长度，就更新ans为length+1，因为length此时已经比刚好满足条件的长度少1
            length=ans;//将length重置为ans
            length_update=false;//将length_update重置为false
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
//    vector<int> nums = {2,3,1,2,4,3};
    vector<int> nums = {1,2,3,4,5};

    cout << s.minSubArrayLen(15, nums);
    return 0;
}