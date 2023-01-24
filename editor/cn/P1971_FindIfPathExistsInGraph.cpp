//有一个具有 n 个顶点的 双向 图，其中每个顶点标记从 0 到 n - 1（包含 0 和 n - 1）。图中的边用一个二维整数数组 edges 表示，其中 
//edges[i] = [ui, vi] 表示顶点 ui 和顶点 vi 之间的双向边。 每个顶点对由 最多一条 边连接，并且没有顶点存在与自身相连的边。 
//
// 请你确定是否存在从顶点 source 开始，到顶点 destination 结束的 有效路径 。 
//
// 给你数组 edges 和整数 n、source 和 destination，如果从 source 到 destination 存在 有效路径 ，则返回 
//true，否则返回 false 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
//输出：true
//解释：存在由顶点 0 到顶点 2 的路径:
//- 0 → 1 → 2 
//- 0 → 2
// 
//
// 示例 2： 
// 
// 
//输入：n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
//
//输出：false
//解释：不存在由顶点 0 到顶点 5 的路径.
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 2 * 10⁵ 
// 0 <= edges.length <= 2 * 10⁵ 
// edges[i].length == 2 
// 0 <= ui, vi <= n - 1 
// ui != vi 
// 0 <= source, destination <= n - 1 
// 不存在重复边 
// 不存在指向顶点自身的边 
// 
//
// Related Topics深度优先搜索 | 广度优先搜索 | 并查集 | 图 
//
// 👍 131, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//

#include<bits/stdc++.h>
using namespace std;

class TimeCost
{
public:
    TimeCost()
    {
        start = std::chrono::system_clock::now();
    }

    TimeCost(string name_input) : funName(name_input)
    {
        start = std::chrono::system_clock::now();
    }

    void tic()
    {
        start = std::chrono::system_clock::now();
    }

    double toc()
    {
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> duration = (end - start);
        std::cout << funName << " cost "
                  << duration.count() * std::chrono::seconds::period::num / std::chrono::seconds::period::den
                  << " second " << endl;
        return duration.count();
    }

    double toc_noOut()
    {
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> duration = (end - start);
        return duration.count();
    }

private:
    std::chrono::time_point<chrono::system_clock> start, end;
    std::string funName = "xxx fun ";
};
/*
* 寻找图中是否存在路径
* @author fjl
* @date 2023-01-24 13:56:14
*/
//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    bool validPath(const int n, vector<vector<int>>& edges, int source, int destination) {
//        vector<vector<int>> edge_mat(n);//邻接阵
//        for (int i=edges.size()-1; i>=0; --i)
//        {//初始化邻接阵
//            edge_mat[edges[i][0]].push_back(edges[i][1]);
//            edge_mat[edges[i][1]].push_back(edges[i][0]);
//        }
//        vector<bool> view_set(n,false);//是否已经查看过
//        return dfs(source,destination,edge_mat,view_set);
//    }
//    bool dfs(int source,int destination,vector<vector<int>>& edge_mat, vector<bool>& view_set)
//    {
//        if(source==destination)return true;
//        view_set[source]=true;//标记已经查看过
//        for (auto item:edge_mat[source])
//        {//遍历邻节点, 如果未标记且存在到destination的路径
//            if(!view_set[item]&& dfs(item,destination,edge_mat,view_set))
//                return true;
//        }
//        return false;
//    }
//};
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

//class Solution {
//public:
//    bool validPath(const int n, vector<vector<int>>& edges, int source, int destination) {
//        if(source==destination) return true;
//        vector<vector<int>> edge_mat(n);//邻接阵
//        for (int i=edges.size()-1; i>=0; --i)
//        {//初始化邻接阵
//            edge_mat[edges[i][0]].push_back(edges[i][1]);
//            edge_mat[edges[i][1]].push_back(edges[i][0]);
//        }
//        queue<int> q;//队列
//        q.push(source);
//        int node=source;
//        vector<bool> view_set(n,false);
//        view_set[source]=true;
//        while(!q.empty())
//        {
//            node=q.front();
//            q.pop();//弹出
//            for(auto item:edge_mat[node])
//            {//遍历邻节点
//                if(!view_set[item])//如果之前没有访问过
//                {
//                    q.emplace(item);
//                    view_set[item]= true;
//                    //如果访问到目标节点,返回true
//                    if(view_set[destination])return true;
//                }
//            }
//        }
//        return false;
//    }
//};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
//   int n=3;
//   vector<vector<int>> edges={{0,1},{0,2},{3,5},{5,4},{4,3}};
//   cout<<s.validPath(6,edges,0,5);
//   vector<vector<int>> edges={{0,1},{1,2},{2,0}};
//   cout<<s.validPath(3,edges,0,2);
    vector<vector<int>> edges={{0,4}};
    cout<<s.validPath(5,edges,0,4);
}