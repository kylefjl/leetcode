//给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。 
//
// 叶子节点 是指没有子节点的节点。 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,3,null,5]
//输出：["1->2->5","1->3"]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：["1"]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [1, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 深度优先搜索 字符串 回溯 二叉树 👍 1110 👎 0

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
* 二叉树的所有路径
* @author fjl
* @date 2024-03-19 09:51:25
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        construct_paths(root,path,result);
        return result;


    }
    //回溯法
    void construct_paths(TreeNode* root,string & path, vector<string> &result)// 构造路径
    {
        if(root==nullptr)return ;
        if(root->left==nullptr&&root->right==nullptr)//叶子节点
        {
            auto val_s=to_string(root->val);
            path+= val_s;// 路径添加 val ，不用添加 ->
            result.push_back(path);//将完整路径添加到结果中
           for(int i=0;i<val_s.size();++i)//弹出，恢复path
           {
               path.pop_back();
           }
            return;
        }
        if (root->left!=nullptr)
        {
            auto val_s=to_string(root->val);
            path=path+val_s+"->";//路径添加 val ->
            construct_paths(root->left,path,result);//继续查找路径
            for(int i=0;i<val_s.size()+2;++i)//弹出，恢复path
            {
                path.pop_back();
            }
        }
        if (root->right!=nullptr)
        {
            auto val_s=to_string(root->val);
            path=path+ val_s+"->";
            construct_paths(root->right,path,result);
            for(int i=0;i<val_s.size()+2;++i)
            {
                path.pop_back();
            }
        }
        return;

    }
    vector<string> result;
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
}