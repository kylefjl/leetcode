# 寻找图中是否存在路径

## BFS

广度优先搜索

```cc
class Solution {
public:
    bool validPath(const int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        vector<vector<int>> edge_mat(n);//邻接阵
        for (int i=edges.size()-1; i>=0; --i)
        {//初始化邻接阵
            edge_mat[edges[i][0]].push_back(edges[i][1]);
            edge_mat[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;//队列
        q.push(source);
        int node=source;
        vector<bool> view_set(n,false);
        view_set[source]=true;
        while(!q.empty())
        {
            node=q.front();
            q.pop();//弹出
            for(auto item:edge_mat[node])
            {//遍历邻节点
                if(!view_set[item])//如果之前没有访问过
                {
                    q.emplace(item);
                    view_set[item]= true;
                    //如果访问到目标节点,返回true
                    if(view_set[destination])return true;
                }
            }
        }
        return false;
    }
};
```

>执行耗时:484 ms,击败了35.75% 的C++用户
>内存消耗:152.5 MB,击败了29.85% 的C++用户

## DFS

深度优先搜索

```cc
class Solution {
public:
    bool validPath(const int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> edge_mat(n);//邻接阵
        for (int i=edges.size()-1; i>=0; --i)
        {//初始化邻接阵
            edge_mat[edges[i][0]].push_back(edges[i][1]);
            edge_mat[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> view_set(n,false);//是否已经查看过
        return dfs(source,destination,edge_mat,view_set);
    }
    bool dfs(int source,int destination,vector<vector<int>>& edge_mat, vector<bool>& view_set)
    {
        if(source==destination)return true;
        view_set[source]=true;//标记已经查看过
        for (auto item:edge_mat[source])
        {//遍历邻节点, 如果未标记且存在到destination的路径
            if(!view_set[item]&& dfs(item,destination,edge_mat,view_set))
                return true;
        }
        return false;
    }
};
```

>执行耗时:468 ms,击败了42.18% 的C++用户
>内存消耗:183.5 MB,击败了20.45% 的C++用户



## 并查集

https://zhuanlan.zhihu.com/p/93647900

定义一个UnionFind类来实现

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
    int merge(int a,int b)
    {
        auto a_root=find(a);
        auto b_root=find(b);
        if(a_root==b_root)return a_root;//如果是一个集合,退出

        if(parent[a_root].second>parent[b_root].second)
        {
            return parent[b_root].first=a_root;//合并,小树往大数合
        }
        else
        {//更新树的最大深度
            parent[b_root].second=max(parent[a_root].second+1,parent[b_root].second);
            return parent[a_root].first=b_root;//合并
        }

    }
    //查询x,y是不是一个集合内
    inline bool connect(int x, int y) { return find(x) == find(y); }
private:
    vector<pair<int,int>> parent;//first为父节点,second为树的最大深度

};
class Solution {
public:
    bool validPath(const int n, vector<vector<int>>& edges, int source, int destination)
    {
        UnionFind uf(n);//并查集
        const auto edge_num=edges.size();
        for(int i=0;i<edge_num;++i)//如果两个集合的有边,则合并两个集合
        {
            uf.merge(edges[i][0],edges[i][1]);
        }
        return uf.connect(source,destination);
    }
};
```

