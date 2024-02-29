//给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[
//b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）： 
//
// 
// 0 <= a, b, c, d < n 
// a、b、c 和 d 互不相同 
// nums[a] + nums[b] + nums[c] + nums[d] == target 
// 
//
// 你可以按 任意顺序 返回答案 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,0,-1,0,-2,2], target = 0
//输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [2,2,2,2,2], target = 8
//输出：[[2,2,2,2]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// -10⁹ <= nums[i] <= 10⁹ 
// -10⁹ <= target <= 10⁹ 
// 
//
// Related Topics 数组 双指针 排序 👍 1869 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 四数之和
* @author fjl
* @date 2024-02-28 20:47:59
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums,  int target) {
        std::sort(nums.begin(),nums.end());//先排序
        std::vector<vector<int>> result;//存储结果
        auto end_idx=nums.end()-1;
        if (nums.size()<4)return result;//如果数组长度小于4直接返回
        for (auto it=nums.begin();it!=end_idx;)
        {
            //从小到大选择一个数作为第一个，调用twoSum求剩下的两个数
            auto pair= threeSum(nums,target-*it,it+1,end_idx);
            if(!pair.empty())//如果有数据说明有四数之和为0
            {
                for(auto item: pair)
                {
                    vector<int> temp{*it,item[0],item[1],item[2]};//
                    result.push_back(temp);//存储结果
                }
            }
            if(*it>target/4)break;//因为不可能4个数都大于target/4，所以it大于等于0证明已遍历所有可能
            int last_num=*it;//存储当前的数字
            while(it!=end_idx&&*it==last_num)it++;//向右移动直到找到下一个不同的数字
        }
        return result;
    };
    vector<vector<int>> threeSum(const vector<int>& sort_nums, long long int target,const vector<int>::iterator& begin_idx,vector<int>::iterator& end_idx)
    {
        std::vector<vector<int>> result;//存储结果
        int last_num;
        for (auto it=begin_idx;it!=end_idx;)
        {
            //从小到大选择一个数作为第一个，调用twoSum求剩下的两个数
            auto pair= twoSum(sort_nums,target-*it,it+1,end_idx);
            if(!pair.empty())//如果有数据说明有三数之和为0
            {
                for(auto item: pair)
                {
                    vector<int> temp{*it,item[0],item[1]};//
                    result.push_back(temp);//存储结果
                }
            }
            if(*it>target/3)break;//因为不可能3个数都大于target/3，所以it大于等于0证明已遍历所有可能
            last_num=*it;//存储当前的数字
            while(it!=end_idx&&*it==last_num)it++;//向右移动直到找到下一个不同的数字
        }
        return result;
    }
//在sort_nums中查找两数之和等于target，begin_idx、end_idx指定了范围
    vector<vector<int>> twoSum(const vector<int>& sort_nums, long long int target,const vector<int>::iterator& begin_idx,vector<int>::iterator& end_idx)
    {
        vector<vector<int>> result;
        auto left_it=begin_idx;
        auto right_it=end_idx;
        int count=0,last_right_num,last_left_num;
        for(;left_it<right_it;)//访问完毕退出
        {//左右两个迭代器向中间靠近
            if(target<2*(*left_it)||target>2*(*right_it))break;//不可能存在两数之和等于target
            if(*left_it+*right_it>target)
            {
                last_right_num=*right_it;
                //如果相加大于目标，为了变小，只能右边数字再小一些
                while(*right_it==last_right_num&&left_it!=right_it)
                    right_it--;
            }
            else if (*left_it+*right_it<target)
            {   //如果相加小于目标，为了变大，只能左边数字再大一些
                last_left_num=*left_it;
                while(*left_it==last_left_num&&left_it!=right_it)
                    left_it++;
            }
            else if (*left_it+*right_it==target)
            {
                vector<int> temp={*left_it,*right_it};
                result.push_back(temp);//找到结果则添加到序列里，然后接着查找
                last_right_num=*right_it,last_left_num=*left_it;
                //左右同时移动直到找到下一个不同的数字
                while(*right_it==last_right_num&&left_it!=right_it)
                    right_it--;
                while(*left_it==last_left_num&&left_it!=right_it)
                    left_it++;
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    int target = -294967296;
    vector<vector<int>> result = s.fourSum(nums, target);
    for (const auto& item: result)
    {
        for (auto i: item)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}