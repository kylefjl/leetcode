
//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那 两个 整数，并返回它们的数组下标。 
//
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。 
//
// 你可以按任意顺序返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,7,11,15], target = 9
//输出：[0,1]
//解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,4], target = 6
//输出：[1,2]
// 
//
// 示例 3： 
//
// 
//输入：nums = [3,3], target = 6
//输出：[0,1]
// 
//
// 
//
// 提示： 
//
// 
// 2 <= nums.length <= 10⁴ 
// -10⁹ <= nums[i] <= 10⁹ 
// -10⁹ <= target <= 10⁹ 
// 只会存在一个有效答案 
// 
//
// 
//
// 进阶：你可以想出一个时间复杂度小于 O(n²) 的算法吗？ 
//
// Related Topics 数组 哈希表 👍 16101 👎 0

#include<bits/stdc++.h>

using namespace std;
/*
 * 两数之和
 * @author fjl
 * @date 2023-01-12 20:06:59
 */
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //排序+左右查找
      vector<int> twoSum1(vector<int>& nums, int target) {
          vector<int> sort_nums=nums;//保存原始数据
          std::sort(sort_nums.begin(),sort_nums.end());//先排序
          vector<int> result;
          auto left_it=sort_nums.begin();
          auto right_it=sort_nums.end()-1;//尾迭代器-1，指向有效数据
          for(;left_it!=right_it;)//左右两边相等则访问完毕退出
          {//左右两个迭代器向中间靠近
              if(*left_it+*right_it>target)right_it--;//如果相加大于目标，为了变小，只能右边数字再小一些
              else if (*left_it+*right_it<target)left_it++;//如果相加小于目标，为了变大，只能左边数字再大一些
              else if (*left_it+*right_it==target)break;//相等退出
          }
          for(int i=0;i<nums.size();i++)
          {
              if(nums[i]==*left_it||nums[i]==*right_it)result.push_back(i);//在原始数据中查找数原本的位置记录在result
          }
          return result;
      }

    //哈希表
    vector<int> twoSum2(vector<int> &nums, int target) {
        unordered_multimap<int, int> hash_map;//允许重复的hashtable
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {//插入
            hash_map.emplace(std::make_pair(nums[i], i));
        }
        for (int i = 0; i < nums.size(); i++) {
            auto position = hash_map.find(target - nums[i]);
            if (position != hash_map.end() && position->second != i) {//如果有target - nums[i]对应的数且不是自身
                if (hash_map.count(position->first) == 1) {//如果对应键只有一个数的话，直接返回
                    return {position->second, i};
                }
                else //对应键有多个数
                {
                    auto range = hash_map.equal_range(target - nums[i]);//get数的首位迭代器
                    for (auto i = range.first; i != range.second; ++i)
                    {
                        result.push_back(i->second);
                    }
                    return result;
                }
            }
        }
        return {};

    }

};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    vector<int> input_nums = {3, 3};
    int target = 6;
    auto result = s.twoSum1(input_nums, target);
    for (auto item: result)
        cout << item << " ";
}
