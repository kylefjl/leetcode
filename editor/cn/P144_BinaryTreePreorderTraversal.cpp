//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,null,2,3]
//输出：[1,2,3]
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
// 示例 4： 
// 
// 
//输入：root = [1,2]
//输出：[1,2]
// 
//
// 示例 5： 
// 
// 
//输入：root = [1,null,2]
//输出：[1,2]
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
// 进阶：递归算法很简单，你可以通过迭代算法完成吗？ 
//
// Related Topics 栈 树 深度优先搜索 二叉树 👍 1233 👎 0

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
* 二叉树的前序遍历
* @author fjl
* @date 2024-03-11 14:44:02
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return out;
        preOrder_iteration(root);
        return out;
    }
    void preOrder(TreeNode* root)
    {
        if (root == nullptr) return ;
        out.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
    void preOrder_iteration(TreeNode* root)
    {
        if (root == nullptr) return;
        stack<TreeNode*> node;
        TreeNode* temp;
        node.push(root );
        // 中 左 右 顺序 先压右节点再压左节点 保证左节点先出栈 右节点后出栈 访问顺序与前序遍历一致
        while(!node.empty())
        {
            temp=node.top();
            out.push_back(temp->val);
            node.pop();
            if(temp->right!=nullptr){

                node.push(temp->right);
            }
            if(temp->left!=nullptr){
                node.push(temp->left);
            }

        }
    }
    vector <int> out;
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
}