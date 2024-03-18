//给你一个二叉树的根节点 root ， 检查它是否轴对称。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,2,3,4,4,3]
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：root = [1,2,2,null,3,null,3]
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [1, 1000] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：你可以运用递归和迭代两种方法解决这个问题吗？ 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 2671 👎 0

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0),left(nullptr), right(nullptr){}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
* 对称二叉树
* @author fjl
* @date 2024-03-15 17:25:01
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
    bool isSymmetric(TreeNode* root) {
        return check(root,root);//递归
    }
    // 递归函数
//   判断两个根结点具有相同的值
//   每个树的右子树都与另一个树的左子树镜像对称
    bool check(TreeNode*root_1,TreeNode*root_2)
    {

        if(root_1!=nullptr&&root_2!=nullptr)
        {
            if (root_1->val==root_2->val)//判断两个根结点具有相同的值
            {
                //每个树的右子树都与另一个树的左子树镜像对称
                return check(root_1->right,root_2->left)&&check(root_2->right,root_1->left);
            }
            return false;//不对称
        }
        else if(root_1==nullptr&&root_2==nullptr)//两个根结点都为空
        {
            return true;//对称
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    auto* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left =nullptr;
    root->right->right = new TreeNode(3);
    cout<<s.isSymmetric(root)<<endl;

}