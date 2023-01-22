# 验证二叉搜索树

## 迭代

思路：依靠中序遍历（先左子树，再根，再右子树）的特性，如果值不是以此递增的话就不是二叉搜索树

```cc
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
```

>执行耗时:4 ms,击败了98.02% 的C++用户
>内存消耗:21.1 MB,击败了76.74% 的C++用户