//给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建: 
//
// 
// 创建一个根节点，其值为 nums 中的最大值。 
// 递归地在最大值 左边 的 子数组前缀上 构建左子树。 
// 递归地在最大值 右边 的 子数组后缀上 构建右子树。 
// 
//
// 返回 nums 构建的 最大二叉树 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：nums = [3,2,1,6,0,5]
//输出：[6,3,5,null,2,0,null,null,1]
//解释：递归调用如下所示：
//- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
//    - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
//        - 空数组，无子节点。
//        - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
//            - 空数组，无子节点。
//            - 只有一个元素，所以子节点是一个值为 1 的节点。
//    - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
//        - 只有一个元素，所以子节点是一个值为 0 的节点。
//        - 空数组，无子节点。
// 
//
// 示例 2： 
// 
// 
//输入：nums = [3,2,1]
//输出：[3,null,2,null,1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 1000 
// 0 <= nums[i] <= 1000 
// nums 中的所有整数 互不相同 
// 
//
// Related Topics 栈 树 数组 分治 二叉树 单调栈 👍 773 👎 0

#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
* 最大二叉树
* @author fjl
* @date 2024-03-21 20:47:53
*/
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> stk;
        TreeNode * temp_node=nullptr;
        for (int num : nums)
        {
            temp_node= new TreeNode(num);// 申请一个新的节点

            while (!stk.empty()) // 如果栈不为空
            {
                if (stk.top()->val>num) // 如果栈顶元素大于当前元素 将当前节点作为栈顶元素的右子树
                {
                    stk.top()->right=temp_node;// 将当前节点作为栈顶元素的右子树
                    stk.emplace(  temp_node);// 将当前节点入栈
                    break;
                }
                else
                {
                    temp_node->left= stk.top(); // 如果栈顶元素小于当前元素 将栈顶元素作为当前节点的左子树
                    stk.pop();// 弹出栈顶元素,继续查找可以作为当前节点的父节点的元素，直到栈为空
                }
            }
            if(stk.empty())stk.emplace( temp_node); // 如果栈为空 将当前节点入栈 说明当前节点是最大的
        }
        TreeNode* root=nullptr;// 返回根节点
        while (!stk.empty())
        {
            root=stk.top();
            stk.pop();
        }
        return root;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    vector<int> nums={3,2,1,6,0,5};
    auto* root=s.constructMaximumBinaryTree(nums);


    return 0;
}