//给定一个包含红色、白色和蓝色、共 n 个元素的数组
// nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。 
//
// 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。 
//
// 
// 
//
// 必须在不使用库内置的 sort 函数的情况下解决这个问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,0,2,1,1,0]
//输出：[0,0,1,1,2,2]
// 
//
// 示例 2： 
//
// 
//输入：nums = [2,0,1]
//输出：[0,1,2]
// 
//
// 
//
// 提示： 
//
// 
// n == nums.length 
// 1 <= n <= 300 
// nums[i] 为 0、1 或 2 
// 
//
// 
//
// 进阶： 
//
// 
// 你能想出一个仅使用常数空间的一趟扫描算法吗？ 
// 
//
// Related Topics 数组 双指针 排序 👍 1560 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 颜色分类
* @author name
* @date 2023-04-01 23:21:23
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public://（计数排序）
    void sortColors(vector<int>& nums) {
        int count[3]={0,0,0};//存储各个颜色的个数
        for (int i = 0; i < nums.size(); ++i)
        {
            ++count[nums[i]];
        }
        //按照颜色数量重写nums。
        for (int i = 0; i < count[0]; ++i)nums[i]=0;
        for (int i = 0; i < count[1]; ++i)nums[i+count[0]]=1;
        for (int i = 0; i < count[2]; ++i)nums[i+count[0]+count[1]]=2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
}