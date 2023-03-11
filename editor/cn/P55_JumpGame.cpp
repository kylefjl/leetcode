//给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。 
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。 
//
// 判断你是否能够到达最后一个下标。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,3,1,1,4]
//输出：true
//解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,1,0,4]
//输出：false
//解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 3 * 10⁴ 
// 0 <= nums[i] <= 10⁵ 
// 
//
// Related Topics 贪心 数组 动态规划 👍 2206 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 跳跃游戏
* @author fjl
* @date 2023-02-24 23:56:48
*/
//leetcode submit region begin(Prohibit modification and deletion)
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
    //递归，会超时
    bool canJump(vector<int >::iterator  begin,vector<int>::iterator end)
    {
        if(end-begin<=1)return true;
        for (auto it=begin;it+1<end;++it)
        {
            if(end-(it+1)<=*it)//it位置可以跳到最后一个位置
            {
                if(canJump(begin,it+1))return true;//查询从begin处是否可以跳到it
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   vector<int> nums={2,0,0};
   std::cout<<"can Jump :"<<s.canJump(nums)<<std::endl;
}