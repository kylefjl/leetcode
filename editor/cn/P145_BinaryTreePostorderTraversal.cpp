//给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,null,2,3]
//输出：[3,2,1]
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
// 树中节点的数目在范围 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：递归算法很简单，你可以通过迭代算法完成吗？ 
//
// Related Topics 栈 树 深度优先搜索 二叉树 👍 1165 👎 0

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
* 二叉树的后序遍历
* @author fjl
* @date 2024-03-11 15:01:14
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
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder_iter(root);
        return out;

    }
    void postOrder(TreeNode* root)
    {
        if(root==nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        out.push_back(root->val);

    }
    void postOrder_iter(TreeNode* root)
    {
        if (root == nullptr) return;
        stack<TreeNode*> node_stack;
        TreeNode* temp=root;
        //后序遍历 左右中
        TreeNode *prev = nullptr; // 前一个节点 用来判断右节点是否已经访问
        while(temp!=nullptr||!node_stack.empty())// 当前节点不为空或者栈不为空
        {
            if(temp!=nullptr)// 当前节点不为空
            {
                node_stack.push(temp);//当前节点入栈
                temp=temp->left;//左节点
            }
            else
            {
                temp=node_stack.top();// 访问当前节点
                if(temp->right==nullptr|| temp->right == prev)// 右节点为空或者右节点已经访问
                {
                    node_stack.pop();//出栈
                    out.push_back(temp->val);// 存入结果
                    prev = temp;// 记录当前节点
                    temp=nullptr;
                }
                else // 右节点不为空 且未访问 右节点入栈
                    temp=temp->right;
            }
        }

    }

    vector <int> out;
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    //3,1,null,null,2
   Solution s;
    TreeNode c(3);
    TreeNode b(2);
    TreeNode a(1, nullptr, &b);
    TreeNode root(3,&a,&c);

   auto result= s.postorderTraversal(&root);
    for(auto item:result)
    {
        cout<<item<<endl;
    }
    return 0;


}