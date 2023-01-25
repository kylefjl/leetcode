//树可以看成是一个连通且 无环 的 无向 图。 
//
// 给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。图的信
//息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。 
//
// 请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的边。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: edges = [[1,2], [1,3], [2,3]]
//输出: [2,3]
// 
//
// 示例 2： 
//
// 
//
// 
//输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
//输出: [1,4]
// 
//
// 
//
// 提示: 
//
// 
// n == edges.length 
// 3 <= n <= 1000 
// edges[i].length == 2 
// 1 <= ai < bi <= edges.length 
// ai != bi 
// edges 中无重复元素 
// 给定的图是连通的 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 👍 532 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 冗余连接
* @author fjl
* @date 2023-01-25 11:46:15
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
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
//   vector<vector<int>> edge={{1,2}, {1,3}, {2,3}};
   vector<vector<int>> edge={{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
   auto result=s.findRedundantConnection(edge);
    cout<<result[0]<<' '<<result[1];
}