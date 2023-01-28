//给定二叉搜索树（BST）的根节点
// root 和要插入树中的值
// value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。 
//
// 注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [4,2,7,1,3], val = 5
    //输出：[4,2,7,1,3,5]
// 
//
// 示例 2： 
//
// 
//输入：root = [40,20,60,10,30,50,70], val = 25
//输出：[40,20,60,10,30,50,70,null,null,25]
// 
//
// 示例 3： 
//
// 
//输入：root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
//输出：[4,2,7,1,3,5]
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数将在
// [0, 10⁴]的范围内。
// 
// -10⁸ <= Node.val <= 10⁸ 
// 所有值 
// Node.val 是 独一无二 的。 
// -10⁸ <= val <= 10⁸ 
// 保证 val 在原始BST中不存在。 
// 
//
// Related Topics 树 二叉搜索树 二叉树 👍 425 👎 0

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
* 二叉搜索树中的插入操作
* @author fjl
* @date 2023-01-28 16:02:22
*/
//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        BSTinsert(root,val);//调用
        return root;
    }
    void BSTinsert(TreeNode*& root, int val) {
        if(root== nullptr)
        {//添加到节点
            root=new TreeNode(val, nullptr, nullptr);
            return;
        }
        if(val<root->val)BSTinsert(root->left, val);
        else  BSTinsert(root->right,val);//val比root大，往右子树插
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;

    TreeNode g(13);
    TreeNode f(9);
    TreeNode e(5);
    TreeNode d(1);
    TreeNode c(11,&f,&g);
    TreeNode b(3, &d, &e);
    TreeNode a(7, &b, &c);
    s.insertIntoBST(&a,2);
}