//给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历） 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[[15,7],[9,20],[3]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：[[1]]
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 2000] 内 
// -1000 <= Node.val <= 1000 
// 
//
// Related Topics 树 广度优先搜索 二叉树 👍 786 👎 0

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
* 二叉树的层序遍历 II
* @author fjl
* @date 2024-03-12 10:38:24
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root== nullptr)return {};

        queue<TreeNode*> q;//队列
        q.push(root);//先把根结点加入
        vector<vector<int>> result;
        stack<vector<int>> s_result; //存储结果的栈 用于反转
        int n = q.size();//每层的节点个数
        vector<int> temp_vector;//储存每层的节点
        while(!q.empty())
        {
            temp_vector.push_back(q.front()->val);
            //如果左右子节点非空，添加到队列
            if(q.front()->left!= nullptr)q.push(q.front()->left);
            if(q.front()->right!= nullptr)q.push(q.front()->right);
            q.pop();//弹出节点；
            --n;//节点数减1
            if(n==0){//访问完毕
                s_result.push(std::move(temp_vector));//移动push
                n=q.size();//n更新为下一层的个数
            }

        }
        while (s_result.size()>0)
        {
            result.push_back(s_result.top());//把层序遍历的结果从下往上 push 到 result
            s_result.pop();
        }
        return std::move(result);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
}