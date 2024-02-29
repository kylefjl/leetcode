//给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足： 
//
// 
// 0 <= i, j, k, l < n 
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
//输出：2
//解释：
//两个元组如下：
//1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1)
// + 2 = 0
//2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1)
// + 0 = 0
// 
//
// 示例 2： 
//
// 
//输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// n == nums1.length 
// n == nums2.length 
// n == nums3.length 
// n == nums4.length 
// 1 <= n <= 200 
// -2²⁸ <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2²⁸ 
// 
//
// Related Topics 数组 哈希表 👍 974 👎 0

#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*
* 四数相加 II
* @author fjl
* @date 2024-02-28 19:46:28
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // 4个数组相加分解成两个数组各自相加，然后再相加等于0  复杂度O(n^2) 如果直接四个数组相加复杂度O(n^4)
        unordered_map<int,int> countAB;//存储A B 两个数组相加的结果
        int result=0;
        for (int u : nums1) {
            for (int v : nums2) {
                ++countAB[u + v];//存储A B 两个数组相加的结果(key) 以及出现的次数(value)
            }
        }
        for(int u:nums3)
        {
            for(int v:nums4)
            {
                result+=countAB[-u-v];//C D 两个数组相加的结果的相反数在A B 两个数组相加的结果中出现的次数 就是满足条件的元组个数
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};
    cout<<s.fourSumCount(nums1,nums2,nums3,nums4);

}