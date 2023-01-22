//给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。 
//
// 有效 二叉搜索树定义如下： 
//
// 
// 节点的左子树只包含 小于 当前节点的数。 
// 节点的右子树只包含 大于 当前节点的数。 
// 所有左子树和右子树自身必须也是二叉搜索树。 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [2,1,3]
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：root = [5,1,4,null,null,3,6]
//输出：false
//解释：根节点的值是 5 ，但是右子节点的值是 4 。
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目范围在[1, 10⁴] 内 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
//
// Related Topics树 | 深度优先搜索 | 二叉搜索树 | 二叉树 
//
// 👍 1856, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
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
* 验证二叉搜索树
* @author name
* @date 2023-01-21 23:57:00
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
    bool isValidBST(TreeNode* root)
    {
        int lower = numeric_limits<int>::min();//给lower设个最小
        first_node = true;//还没找到中序遍历的第一个节点
        return isValidBST(root, lower);
    }
    bool isValidBST(TreeNode* root,int& lower) {
        if(root== nullptr) return true;
        if(!isValidBST(root->left,lower))return false;//左子树
        if(root->val>lower || first_node)//如果当前值大于中序遍历的前一个节点
        {                                //或当前节点是第一个节点
            lower=root->val;
            first_node= false;//之后的节点就不是访问的第一个节点了
            return isValidBST(root->right,lower);//右子树
        }
        else return false;
    }
private:
    bool first_node= false;
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
//    TreeNode j(8);
//    TreeNode i(4);
//    TreeNode h(6);
//    TreeNode g(3);
//    TreeNode f(8);
//    TreeNode e(4,&j, nullptr);
//    TreeNode d(7,&h,&i);
//    TreeNode c(4,&f,&g);
//    TreeNode b(1, &d, &e);
//    TreeNode a(-2, &b, &c);


//    TreeNode e(6);
//    TreeNode d(3);
//    TreeNode c(4,&d,&e);
//    TreeNode b(1, nullptr, nullptr);
//    TreeNode a(5, &b, &c);

    TreeNode b(1, nullptr, nullptr);
    TreeNode a(1, nullptr, &b);

  cout<<  s.isValidBST(&a);
}