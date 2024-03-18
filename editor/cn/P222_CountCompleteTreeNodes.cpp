//给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。 
//
// 完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层
//为第 h 层，则该层包含 1~ 2ʰ 个节点。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,3,4,5,6]
//输出：6
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目范围是[0, 5 * 10⁴] 
// 0 <= Node.val <= 5 * 10⁴ 
// 题目数据保证输入的树是 完全二叉树 
// 
//
// 
//
// 进阶：遍历树来统计节点是一种时间复杂度为 O(n) 的简单解决方案。你可以设计一个更快的算法吗？ 
//
// Related Topics 位运算 树 二分查找 二叉树 👍 1109 👎 0

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
* 完全二叉树的节点个数
* @author fjl
* @date 2024-03-18 19:45:42
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
//    比较完全二叉树左右两颗子树的高度：
//    1.如果当前节点左右子树高度相等：当前节点的左子树就是一颗满二叉树，可以直接计算左子树节点个树为：2的左子树高度次方。总的节点个树，则只需再加上右子树的节点树。把右子节点树继续递归求解。
//    2.如果当前节点左右子树高度不相等：则左子树可能不是满二叉树，且右子树是满二叉树，则利用右子树高度就可以求出右子树节点个树。此时只需继续递归求解左子树，就可以得到总节点树。
    int countNodes(TreeNode* root) {
        if(root==nullptr)return 0;
        auto left_level= countLevels(root->left);
        auto right_level= countLevels(root->right);
        if(left_level==right_level)
        {
            return countNodes(root->right)+(std::exp2(left_level)-1)+1;
        }
        else if(left_level>right_level)
        {
            return countNodes(root->left)+(std::exp2(right_level)-1)+1;
        }
        return 0;//不会执行到这里
    }

    // 计算 完全二叉树树的高度
    int countLevels(TreeNode* root)
    {
        if(root==nullptr)return 0;
        return 1+countLevels(root->left);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    auto root= new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    cout<<s.countNodes(root)<<endl;
    return 0;

}