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
        if(root == nullptr) return out_vector;
        inorder_iter(root);
        return std::move(out_vector);//移动复制
    }
    //重载，out_vector 用来储存输出
    void inorder(TreeNode* root) {
        if(root == nullptr) return ;
        inorder(root->left);
        out_vector.push_back(root->val);
        inorder(root->right);
    }

    //迭代 中序遍历
    void inorder_iter(TreeNode* root) {
        if (root == nullptr) return;
        stack<TreeNode*> node_stack;
        TreeNode* temp=root;
        //中序遍历树 左根右  所以出栈跟在左节点入栈之后 ：找到最左边的节点 插入 输出栈 然后找右节点 插入
         while(temp!=nullptr||!node_stack.empty())// 当前节点不为空或者栈不为空
        {
            if(temp!=nullptr)// 当前节点不为空
            {
                node_stack.push(temp);//当前节点入栈
                temp=temp->left;//左节点
            }
            else//当前节点为空
            {
                temp=node_stack.top();//当前节点出栈
                node_stack.pop();//出栈
                out_vector.push_back(temp->val);//
                temp=temp->right;//右节点

            }
        }
    }
    vector<int > out_vector;

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