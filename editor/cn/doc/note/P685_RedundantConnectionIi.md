# 冗余连接Ⅱ

## 并查集

分类讨论

- **情况1：**有入度为2的节点
  - 找到这个节点，判断没有指向这个节点的一条边后还会联通吗，如果没有这条边还是联通则说明这条边是多余的，否则说明另一条是多余的
- **情况2：**有有向环，没有入度为2的节点：
  - 按照冗余连接Ⅰ找环即可



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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        const int edge_num=edges.size();
        vector<int>  inDegree(edge_num,0);
        for(int i=0;i<edge_num;++i)
        {
            if((++inDegree[edges[i][1] - 1])==2)//如果存在入度为2的情况，则多余的一条边肯定跟这个节点有关
            {//如果在不包括这条边的情况下有路径，则这条边肯定是多余的
                if(validPath(edge_num,edges,edges[i][1]-1 ,edges[i][0]-1,i))
                    return edges[i];
                else //否则多余的肯定是指向当前节点的另一条边
                {
                    for(int j=0;j<i;++j)
                    { if(edges[j][1]==edges[i][1])return edges[j] ;}
                }
            }
        }
        //如果没有入度为2的情况，则肯定是出现了环
        UnionFind uf(edge_num);//节点数等于边数
        for(int i=0;i<edge_num;++i)//对环的情况进行处理
        {
            //如果加入这条边后出现了环，则肯定是这条边多余
            if(!uf.merge(edges[i][0]-1,edges[i][1]-1).empty())return edges[i];
        }
        return {};
    }
    // 是否存在从顶点 source 开始，到顶点 destination 结束的 有效路径,不包括exclude_idx。
    bool validPath(const int n, vector<vector<int>>& edges, int source, int destination,int exclude_idx)
    {
        UnionFind uf(n);//并查集
        const auto edge_num=edges.size();
        for(int i=0;i<edge_num;++i)//如果两个集合的有边,则合并两个集合
        {
            if(exclude_idx==i)continue;
            uf.merge(edges[i][0]-1,edges[i][1]-1);
        }
        return uf.connect(source,destination);
    }
};

```

>执行耗时:4 ms,击败了97.05% 的C++用户
>内存消耗:9.3 MB,击败了43.46% 的C++用户