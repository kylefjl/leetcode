//给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: [1,2,3,null,5,null,4]
//输出: [1,3,4]
// 
//
// 示例 2: 
//
// 
//输入: [1,null,3]
//输出: [1,3]
// 
//
// 示例 3: 
//
// 
//输入: []
//输出: []
// 
//
// 
//
// 提示: 
//
// 
// 二叉树的节点个数的范围是 [0,100] 
// 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1039 👎 0

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
* 二叉树的右视图
* @author fjl
* @date 2024-03-12 11:05:30
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
    vector<int> rightSideView(TreeNode* root) {
         rightSideView_dfs(root,1);
        return result;
    }
    vector<int> rightSideView_bfs(TreeNode* root) {
        if(root== nullptr)return {};
        queue<TreeNode*> q;//队列
        q.push(root);//先把根结点加入
        int n = q.size();//每层的节点个数
        vector<int> temp_vector;//储存每层的节点
        while(!q.empty())
        {
            temp_vector.push_back(q.front()->val);//
            //如果左右子节点非空，添加到队列
            if(q.front()->left!= nullptr)q.push(q.front()->left);
            if(q.front()->right!= nullptr)q.push(q.front()->right);
            q.pop();//弹出节点；
            --n;//节点数减1
            if(n==0){//访问完毕
                result.push_back(temp_vector.back());//取最右边的节点
                n=q.size();//n更新为下一层的个数
            }
        }
        return std::move(result);
    }

    // dfs 深度优先搜索 递归
    void rightSideView_dfs(TreeNode* root,int n)
    {
        if (root!= nullptr)
        {
            if(result.size()<n)result.push_back(root->val);
            if(root->right!= nullptr)rightSideView_dfs(root->right,n+1);
            if(root->left!= nullptr)rightSideView_dfs(root->left,n+1);
        }
    }
    void rightSideView_dfs_iter(TreeNode* root,int n)
    {
        if(root== nullptr)return ;
        result.push_back(root->val);
         stack<pair<TreeNode*,int>> node_stack;
         TreeNode* temp=root;
         int temp_depth = 1;
         int max_depth = 0;
         node_stack.emplace(temp,temp_depth);
         while(!node_stack.empty())// 当前节点不为空或者栈不为空
         {
            temp=node_stack.top().first;//当前节点
            temp_depth = node_stack.top().second;//当前节点的深度
            node_stack.pop();//出栈
            if(temp->left!=nullptr)node_stack.emplace(temp->left,temp_depth+1);//左节点入栈
            if(temp->right!=nullptr)node_stack.emplace(temp->right,temp_depth+1);//右节点后入栈 先出栈  所以右节点先访问 右视
            if (temp_depth>max_depth)//当前节点的深度大于最大深度
            {
                result.push_back(temp->val);//存入结果
                max_depth = temp_depth;
            }
         }
    }
    vector<int> result;

};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    s.rightSideView(root);
    for (int i = 0; i < s.result.size(); ++i) {
        cout<<s.result[i]<<endl;
    }
}