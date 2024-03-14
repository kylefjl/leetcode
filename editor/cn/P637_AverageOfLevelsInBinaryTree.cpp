//给定一个非空二叉树的根节点
// root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10⁻⁵ 以内的答案可以被接受。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[3.00000,14.50000,11.00000]
//解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
//因此返回 [3, 14.5, 11] 。
// 
//
// 示例 2: 
//
// 
//
// 
//输入：root = [3,9,20,15,7]
//输出：[3.00000,14.50000,11.00000]
// 
//
// 
//
// 提示： 
//
// 
// 
//
// 
// 树中节点数量在 [1, 10⁴] 范围内 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 480 👎 0

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
* 二叉树的层平均值
* @author fjl
* @date 2024-03-14 19:55:33
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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root== nullptr)return {};

        queue<TreeNode*> q;//队列
        q.push(root);//先把根结点加入
        int n = q.size();//每层的节点个数
        int i = n;//每层的节点个数 控制循环
        double sum=0 ;//每层的和
        vector<int> temp_vector;//储存每层的节点
        while(!q.empty())
        {
            sum+=q.front()->val;
            //如果左右子节点非空，添加到队列
            if(q.front()->left!= nullptr)q.push(q.front()->left);
            if(q.front()->right!= nullptr)q.push(q.front()->right);
            q.pop();//弹出节点；
            --i;//节点数减1
            if(i==0){//访问完毕
                result.push_back(sum/n);
                n=q.size();//n更新为下一层的个数
                sum=0;//sum清零
                i=n;
            }

        }

        return std::move(result);
    }
    vector<double> result;
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<double> result = s.averageOfLevels(root);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<endl;
    }
}