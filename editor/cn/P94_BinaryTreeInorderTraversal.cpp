//给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,null,2,3]
//输出：[1,3,2]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
//
// Related Topics栈 | 树 | 深度优先搜索 | 二叉树 
//
// 👍 1662, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//

#include<bits/stdc++.h>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0),                                                                                                                               left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
/*
* 二叉树的中序遍历
* @author name
* @date 2023-01-19 23:43:25
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int > out;
        if(root == nullptr) return out;
        inorderTraversal(root->left,out);//左子树
        out.push_back(root->val);//添加到输出vector
        inorderTraversal(root->right,out);//右子树
        return std::move(out);//移动复制
    }
    //重载，out_vector 用来储存输出
    void inorderTraversal(TreeNode*& root,vector<int>& out_vector) {
        if(root == nullptr) return ;
        inorderTraversal(root->left,out_vector);
        out_vector.push_back(root->val);
        inorderTraversal(root->right,out_vector);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    TreeNode c(3);
    TreeNode b(2,&c, nullptr);
    TreeNode a(1, nullptr, &b);
    s.inorderTraversal(&a);

}