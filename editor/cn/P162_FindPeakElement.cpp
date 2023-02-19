//峰值元素是指其值严格大于左右相邻值的元素。 
//
// 给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。 
//
// 你可以假设 nums[-1] = nums[n] = -∞ 。 
//
// 你必须实现时间复杂度为 O(log n) 的算法来解决此问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3,1]
//输出：2
//解释：3 是峰值元素，你的函数应该返回其索引 2。 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,1,3,5,6,4]
//输出：1 或 5 
//解释：你的函数可以返回索引 1，其峰值元素为 2；
//     或者返回索引 5， 其峰值元素为 6。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 1000 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// 对于所有有效的 i 都有 nums[i] != nums[i + 1] 
// 
//
// Related Topics数组 | 二分查找 
//
// 👍 983, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//

#include<bits/stdc++.h>
#include <experimental/random>
using namespace std;

/*
* 寻找峰值
* @author fjl
* @date 2023-02-18 14:54:52
*/
//leetcode submit region begin(Prohibit modification and deletion)
#include <experimental/random>
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
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
vector<int > input ={1,2,3,1};
//vector<int > input ={1,2,1,3,5,6,4};
std::cout<<s.findPeakElement(input);
}