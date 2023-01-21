# 二叉树的中序遍历

# 递归

很简单，先左子树，再根，再右子树

```cc
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int > out;
        if(root == nullptr) return out;
        inorderTraversal(root->left,out);//左子树
        out.push_back(root->val);//添加到输出vector
        inorderTraversal(root->right,out);//右子树
        return std::move(out);//移动复制
    }
    //重载，out_vector 用来储存输出
    void inorderTraversal(TreeNode*& root,vector<int>& out_vector) {
        if(root == nullptr) return ;
        inorderTraversal(root->left,out_vector);
        out_vector.push_back(root->val);
        inorderTraversal(root->right,out_vector);
    }
};
```



>执行耗时:0 ms,击败了100.00% 的C++用户
>内存消耗:8 MB,击败了92.66% 的C++用户