//给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并
//返回这颗 二叉树 。 
//
// 
//
// 示例 1: 
// 
// 
//输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//输出：[3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入：inorder = [-1], postorder = [-1]
//输出：[-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= inorder.length <= 3000 
// postorder.length == inorder.length 
// -3000 <= inorder[i], postorder[i] <= 3000 
// inorder 和 postorder 都由 不同 的值组成 
// postorder 中每一个值都在 inorder 中 
// inorder 保证是树的中序遍历 
// postorder 保证是树的后序遍历 
// 
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 1200 👎 0

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
* 从中序与后序遍历序列构造二叉树
* @author fjl
* @date 2024-03-19 21:29:14
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()||postorder.empty())return nullptr;
        inorder_my=inorder;
        postorder_my=postorder;
        for (int i=0;i<inorder.size();++i)
        {
            inorder_index.emplace(inorder[i],i);
        }
//        return buildTree_it( 0,postorder.size()-1);
        return buildTree_it_inorder( 0,inorder.size()-1,postorder.size()-1);

    }
    //  递归 从后序遍历构建二叉树 left 为子树的在后序遍历中的左界限 root_index 为根节点在后序遍历的索引 复杂度 > O(n)
    TreeNode* buildTree_it(int left,int root_index)//left 为子树的左界限
    {
        if(left>root_index)return nullptr;// 递归终止条件
        auto  root_node= new TreeNode(postorder_my[root_index]);//根节点
        int post_left=new_left(left,root_index);//右子树的左界限
        root_node->right=buildTree_it( post_left,root_index-1);// 构建右子树 递归 post_left 为右子树的左界限 root_index-1 为右子树的右界限
        root_node->left=buildTree_it(left,post_left-1);// 构建左子树 递归 post_left-1 为左子树的右界限
        return root_node;// 返回根节点
    }
    int new_left(int left,int root_index) // 找到右子树的左界限  遍历postorder查找 复杂度较高
    {
        int inorder_root_index=inorder_index.find(postorder_my[root_index])->second;// 根节点在中序遍历的索引
        for(int i=left;i<=root_index;i++ )// 从左界限开始遍历 postorder
        {
            if(inorder_index.find(postorder_my[i])->second>inorder_root_index)// 如果中序遍历的索引大于根节点的索引，说明已经到了右子树 返回新右子树的左界限
            {
                return i;
            }
        }
        return root_index;// 如果没有找到，说明右子树为空，返回根节点索引
    }
    //  递归 从后序遍历构建二叉树   left 为子树的在中序遍历中的左界限 right 为子树的右界限 root_index 为根节点在后序遍历的索引 复杂度  O(n)
    TreeNode* buildTree_it_inorder(int left,int right,int root_index)
    {
        if(left>right)return nullptr;// 递归终止条件
        auto  root_node= new TreeNode(postorder_my[root_index]);//根节点
        int  new_left=inorder_index.at(postorder_my[root_index])+1;//右子树的左界限
        root_node->right=buildTree_it_inorder( new_left,right,root_index-1);// 构建右子树 递归 new_left 为右子树的左界限 right 为右子树的右界限 root_index-1 为右子树的根节点后序索引
        root_node->left=buildTree_it_inorder(left,new_left-2,root_index-(right-new_left+1)-1);// 构建左子树 递归 new_left-2 为左子树的右界限 root_index-(right-new_left+1)-1 为左子树的根节点后序索引
        return root_node;// 返回根节点
    }
    unordered_map<int, int> inorder_index;// 存储中序遍历的值和索引
    vector<int> inorder_my;
    vector<int> postorder_my;
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution solu;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    // [2,1]
//    vector<int> inorder = {2,1};
//    vector<int> postorder = {2,1};
    auto *root = solu.buildTree(inorder,postorder);

    // preorder
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty())
    {
        auto node = s.top();
        s.pop();
        cout<<node->val<<endl;
        if(node->right!= nullptr)
        {
            s.push(node->right);
        }
        if(node->left!= nullptr)
        {
            s.push(node->left);
        }
    }
}