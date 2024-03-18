//给定一个二叉树，找出其最小深度。 
//
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。 
//
// 说明：叶子节点是指没有子节点的节点。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：root = [2,null,3,null,4,null,5,null,6]
//输出：5
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数的范围在 [0, 10⁵] 内 
// -1000 <= Node.val <= 1000 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1168 👎 0

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
* 二叉树的最小深度
* @author fjl
* @date 2024-03-18 16:01:24
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
    int minDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        get_minDepth(root,0);
        return minDepth_int;
    }

    // DFs 递归 递归的参数是当前节点和当前节点的深度
    void get_minDepth(TreeNode* root,int node_num) {
        if(root==nullptr)return ;//
        node_num=node_num+1;// 非nullptr， 深度加一
        if(root->left==nullptr&&root->right==nullptr)//叶子节点
        {
            minDepth_int=min(minDepth_int,node_num);//记录最小深度
        }
        get_minDepth(root->left,node_num);//接着递归
        get_minDepth(root->right,node_num);
    }
    int minDepth_int=INT_MAX;

};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;

   // 2,null,3,null,4,null,5,null,6
   TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
root->right->right=new TreeNode(7);
    cout<<s.minDepth(root)<<endl;
    return 0;

}