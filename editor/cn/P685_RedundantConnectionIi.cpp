//在本问题中，有根树指满足以下条件的 有向 图。该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节
//点没有父节点。 
//
// 输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。附加的边包含在 1 到 n 中的两个不同顶点间，这条
//附加的边不属于树中已存在的边。 
//
// 结果图是一个以边组成的二维数组 edges 。 每个元素是一对 [ui, vi]，用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，其中 ui 是 
//vi 的一个父节点。 
//
// 返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。 
//
// 
//
// 示例 1： 
// 
// 
//输入：edges = [[1,2],[1,3],[2,3]]
//输出：[2,3]
// 
//
// 示例 2： 
// 
// 
//输入：edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
//输出：[4,1]
// 
//
// 
//
// 提示： 
//
// 
// n == edges.length 
// 3 <= n <= 1000 
// edges[i].length == 2 
// 1 <= ui, vi <= n 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 👍 346 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 冗余连接 II
* @author fjl
* @date 2023-01-25 13:51:22
*/
//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    vector<vector<int>> edge={{5,2},{5,1},{3,1},{3,4},{3,5}};
    auto result=s.findRedundantDirectedConnection(edge);
    cout<<result[0]<<' '<<result[1];
}