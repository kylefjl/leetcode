//给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != 
//k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请 
//
// 你返回所有和为 0 且不重复的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
//解释：
//nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
//nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
//nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
//不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
//注意，输出的顺序和三元组的顺序并不重要。
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1,1]
//输出：[]
//解释：唯一可能的三元组和不为 0 。
// 
//
// 示例 3： 
//
// 
//输入：nums = [0,0,0]
//输出：[[0,0,0]]
//解释：唯一可能的三元组和为 0 。
// 
//
// 
//
// 提示： 
//
// 
// 3 <= nums.length <= 3000 
// -10⁵ <= nums[i] <= 10⁵ 
// 
//
// Related Topics数组 | 双指针 | 排序 
//
// 👍 5543, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//

#include <bits/stdc++.h>
using namespace std;
/*
* 三数之和
* @author name
* @date 2023-01-13 20:02:35
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& sort_nums)
    {
        std::sort(sort_nums.begin(),sort_nums.end());//先排序
        std::vector<vector<int>> result;//存储结果
        auto end_idx=sort_nums.end()-1;
        int last_num;
        for (auto it=sort_nums.begin();it!=sort_nums.end();)
        {
            //从小到大选择一个数作为第一个，调用twoSum求剩下的两个数
            auto pair= twoSum(sort_nums,0-*it,it+1,end_idx);
            if(!pair.empty())//如果有数据说明有三数之和为0
            {
                for(auto item: pair)
                {
                    vector<int> temp{*it,item[0],item[1]};//
                    result.push_back(temp);//存储结果
                }
            }
            if(*it>=0)break;//因为不可能3个数都大于0，所以it大于等于0证明已遍历所有可能
            last_num=*it;//存储当前的数字
            while(it!=sort_nums.end()&&*it==last_num)it++;//向右移动直到找到下一个不同的数字
        }
        return result;
    }
//在sort_nums中查找两数之和等于target，begin_idx、end_idx指定了范围
    vector<vector<int>> twoSum(const vector<int>& sort_nums, int target,const vector<int>::iterator& begin_idx,vector<int>::iterator& end_idx)
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
                //如果第一次移动左迭代器，说明对于当前的target来说right_it已经够大了，
                // 又因为以及排了序，所以下一个target肯定大于当前的
                // 所以，可以把当前的right_it作为下一个target查询时的end_idx
                if(count==0)
                {
                    end_idx=right_it;
                    count=1;
                }
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
                //同上
                if(count==0)
                {
                    end_idx=right_it;
                    count=1;
                }
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   vector<int > nums = {2,-2,9,-9,7,-7,2,-7,0,3,8,-9,-3,-9,-3,-10,-5,-4,-3,-9,-9,-4,0,3,-10,-7};
   auto result=s.threeSum(nums);
   for(const auto& item:result)
   {
       for(const auto& item1:item)
       {
           cout<<item1<<" ";
       }
       cout<<endl;

   }

}