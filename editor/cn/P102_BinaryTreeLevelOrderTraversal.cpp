//给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[[3],[9,20],[15,7]]
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
// Related Topics树 | 广度优先搜索 | 二叉树 
//
// 👍 1550, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
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
* 二叉树的层序遍历
* @author fjl
* @date 2023-01-22 23:51:54
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root== nullptr)return {};
        queue<TreeNode*> q;//队列
        q.push(root);//先把根结点加入
        vector<vector<int>> result;
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
                result.push_back(std::move(temp_vector));//移动push
                n=q.size();//n更新为下一层的个数
            }

        }
        return std::move(result);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

void CreatTree(TreeNode* T)
{

}
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        if(root== nullptr)return {};
//        vector<TreeNode*> level={{root}};
//        vector<vector<int>> result={{root->val}};
//        levelOrder(level,result);
//        return std::move(result);
//    }//重载函数，level是上一层的节点序列，result是需要输出的int序列
//    void levelOrder(const vector<TreeNode*>& level,vector<vector<int>>& result) {
//        vector<TreeNode*> cur_level;
//        vector<int> cur_result;
//        for(const auto& item: level)
//        {
//            if(item->left!= nullptr)//非空，添加到result和当前层节点序列
//            {
//                cur_level.push_back(item->left);
//                cur_result.push_back(item->left->val);
//            }
//            if(item->right!= nullptr)//非空，添加到result和当前层节点序列
//            {
//                cur_level.push_back(item->right);
//                cur_result.push_back(item->right->val);
//            }
//        }
//        if(cur_level.empty())return;//如果当前层没有节点，则说明到了最后一层
//        result.push_back(std::move(cur_result));//添加结果
//        levelOrder(cur_level,result);//递归
//    }
//};
int main()
{
   Solution s;
    TreeNode e(6);
    TreeNode d(3);
    TreeNode c(4,&d,&e);
    TreeNode b(1, nullptr, nullptr);
    TreeNode a(5, &b, &c);
    auto  result=s.levelOrder(&a);

    for(const auto& item: result)
    {
        for(auto item1: item)
        {
           cout<<item1;
        }cout<<endl;
    }


}