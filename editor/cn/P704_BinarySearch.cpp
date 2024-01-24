//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否
//则返回 -1。 
//
// 示例 1: 
//
// 输入: nums = [-1,0,3,5,9,12], target = 9
//输出: 4
//解释: 9 出现在 nums 中并且下标为 4
// 
//
// 示例 2: 
//
// 输入: nums = [-1,0,3,5,9,12], target = 2
//输出: -1
//解释: 2 不存在 nums 中因此返回 -1
// 
//
// 
// 解释：
// 提示： 
//
// 
// 你可以假设 nums 中的所有元素是不重复的。 
// n 将在 [1, 10000]之间。 
// nums 的每个元素都将在 [-9999, 9999]之间。 
// 
//
// Related Topics 数组 二分查找 👍 1523 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 二分查找
* @author fjl
* @date 2024-01-23 22:02:15
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int search(vector<int>& nums, int target) {
		        return search_Iteration(nums.begin(),nums.end(),target);
    }
    //二分查找 重载 递归写法
    int search(vector<int>::iterator begin,vector<int>::iterator end,int target){
        auto size=end-begin;
        if(size==0)return -1;//如果没有元素，说明target不存在，返回-1
        int tar_mid= floor(size/2);//二分 floor 向下取整
        if(target==*(begin+tar_mid)){ //如果中间元素等于target，返回中间元素的下标
            return tar_mid;
        }else if(target>*(begin+tar_mid)){
           int  index=search(begin+tar_mid+1,end,target);//如果target大于中间元素，则在右边查找
            return index==-1?-1:(tar_mid+1)+index;//如果右边查找的下标为-1，则说明右边没有找到，返回-1，否则返回右边查找的下标+中间元素的下标+1
        }else{
            return search(begin,begin+tar_mid,target);//如果target小于中间元素，则在左边查找
        }
    }
    //二分查找 重载 迭代写法
    int search_Iteration(vector<int>::iterator begin,vector<int>::iterator end,int target){
        auto size=end-begin;
        int left=0,right=size-1;
        int mid=0;
        while(left<=right)
        {
             mid=left+ std::ceil((right-left)/2.0);//向上取整
            if(*(begin+mid)==target)return mid;//如果中间元素等于target，返回中间元素的下标
            else if(*(begin+mid)>target)right=mid-1;//如果中间元素大于target，则在左边查找
            else left=mid+1;//如果中间元素小于target，则在右边查找
        }
        return -1;//如果没有找到，返回-1
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
//    vector<int> nums={-1,0,3,5,9,12};
    vector<int> nums={-1,0,3,5,9,12};
    int target=9;
    cout<<s.search(nums,target);
}