# 二叉搜索树中的插入操作

不做树的位置调整，直接找到合适的位置插入就行，题目限定没有相等的情况，所以也不用判等

```cc
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
```

>执行耗时:80 ms,击败了80.70% 的C++用户
>内存消耗:55.6 MB,击败了36.51% 的C++用户