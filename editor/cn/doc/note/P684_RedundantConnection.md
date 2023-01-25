# 冗余连接

## 并查集

思路就是找环，由题目知有edges.size()个节点，其中n个节点和n-1个边构成树（连通且无环），所以构成环的那一条边就是需要返回的结果。

```cc
class UnionFind{
public:
    UnionFind(int n):parent(n)//构造函数,n是初始的集合数,类型为int
    {
        while(n--){
            parent[n].first=n;
            parent[n].second=n;
        }
    }
    //查询x的根结点
    int find(const int x)
    {
        return parent[x].first==x?x: (parent[x].first=find(parent[x].first));
    }
    //合并两个集合
    vector<int> merge(int a,int b)
    {
        auto a_root=find(a);
        auto b_root=find(b);
        if(a_root==b_root)return {a_root,b_root};//如果已经是一个集合,则加上这条边就构成了环，返回这条边
        if(parent[a_root].second>parent[b_root].second)
        {
             parent[b_root].first=a_root;//合并,小树往大数合
        }
        else
        {//更新树的最大深度
            parent[b_root].second=max(parent[a_root].second+1,parent[b_root].second);
            parent[a_root].first=b_root;//合并
        }
        return {};//正常合并，返回空
    }
    //查询x,y是不是一个集合内
    inline bool connect(int x, int y) { return find(x) == find(y); }
private:
    vector<pair<int,int>> parent;//first为父节点,second为树的最大深度

};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int edge_num=edges.size();
        UnionFind uf(edge_num);
        for(int i=0;i<edge_num;++i)
        {
           if(!uf.merge(edges[i][0]-1,edges[i][1]-1).empty())
           {
               return edges[i];
           }
        }
        return {};
    }
};
```

>执行耗时:4 ms,击败了95.21% 的C++用户
>内存消耗:8.5 MB,击败了55.76% 的C++用户