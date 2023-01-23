# 二叉树的层序遍历

## 递归

思路：新建一个`vector<TreeNode*>`，用来存储一层的节点序列，然后递归调用levelOrder并传入记录的vector，最终遍历到最后一层

```cc
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root== nullptr)return {};
        vector<TreeNode*> level={{root}};
        vector<vector<int>> result={{root->val}};
        levelOrder(level,result);
        return std::move(result);
    }//重载函数，level是上一层的节点序列，result是需要输出的int序列
    void levelOrder(const vector<TreeNode*>& level,vector<vector<int>>& result) {
        vector<TreeNode*> cur_level;
        vector<int> cur_result;
        for(const auto& item: level)
        {
            if(item->left!= nullptr)//非空，添加到result和当前层节点序列
            {
                cur_level.push_back(item->left);
                cur_result.push_back(item->left->val);
            }
            if(item->right!= nullptr)//非空，添加到result和当前层节点序列
            {
                cur_level.push_back(item->right);
                cur_result.push_back(item->right->val);
            }
        }
        if(cur_level.empty())return;//如果当前层没有节点，则说明到了最后一层
        result.push_back(std::move(cur_result));//添加结果
        levelOrder(cur_level,result);//递归
    }
};
```

>执行耗时:4 ms,击败了68.89% 的C++用户
>内存消耗:12.9 MB,击败了10.15% 的C++用户



## BFS

利用队列的先入先出的特性，实现上一层的节点优先访问

```cc
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
```

>执行耗时:0 ms,击败了100.00% 的C++用户
>内存消耗:12.1 MB,击败了83.76% 的C++用户
