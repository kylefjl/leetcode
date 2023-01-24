省份数量

# 并查集

其实是求连通图 , 直接使用并查集

```cc
class UnionFind{
public:
    UnionFind(int n):parent(n),size(n)//构造函数,n是初始的集合数,类型为int
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
    int merge(int a,int b)
    {
        auto a_root=find(a);
        auto b_root=find(b);
        if(a_root==b_root)return a_root;//如果是一个集合,退出

        if(parent[a_root].second>parent[b_root].second)
        {--size;//合并之后集合数减1
            return parent[b_root].first=a_root;//合并,小树往大数合
        }
        else
        {//更新树的最大深度
            --size;//合并之后集合数减1
            parent[b_root].second=max(parent[a_root].second+1,parent[b_root].second);
            return parent[a_root].first=b_root;//合并
        }

    }
    //查询x,y是不是一个集合内
    inline bool connect(int x, int y) { return find(x) == find(y); }
    inline int getsize() { return size; }
private:
    vector<pair<int,int>> parent;//first为父节点,second为树的最大深度
    int size;//集合个数
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        UnionFind uf(isConnected.size());
        for(int i=isConnected.size()-1;i>=0;--i)
        {
            for(int j=i;j>=0;--j)
            {
                if(isConnected[i][j])uf.merge(i,j);
            }
        }
        return uf.getsize();//返回集合数
    }
};
```

