# 平衡二叉树

思路：只要子树中出现不平衡的情况，则整个树都不是平衡二叉树，所以采用递归

```cc
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return height(root) >=0;
    }
    int height(TreeNode*& root) {
        if (root == nullptr) {
            return 0;
        }
        int leftHeight ;
        int rightHeight;
        if ( (leftHeight = height(root->left)) == -1
            || (rightHeight = height(root->right)) == -1
            || abs(leftHeight - rightHeight) > 1) {
            return -1;//不满足平衡，返回-1
        } else {//满足平衡返回高度（左右子树的最大高度+1）
            return max(leftHeight, rightHeight) + 1;
        }
    }
};
```

>执行耗时:8 ms,击败了87.63% 的C++用户
>内存消耗:20.5 MB,击败了17.05% 的C++用户