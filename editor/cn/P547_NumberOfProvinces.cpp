//
// 
// 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连
//。 
// 
// 
//
// 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。 
//
// 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 
//isConnected[i][j] = 0 表示二者不直接相连。 
//
// 返回矩阵中 省份 的数量。 
//
// 
//
// 示例 1： 
// 
// 
//输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
//输出：2
// 
//
// 示例 2： 
// 
// 
//输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 200 
// n == isConnected.length 
// n == isConnected[i].length 
// isConnected[i][j] 为 1 或 0 
// isConnected[i][i] == 1 
// isConnected[i][j] == isConnected[j][i] 
// 
//
// Related Topics深度优先搜索 | 广度优先搜索 | 并查集 | 图 
//
// 👍 920, 👎 0bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//

#include<bits/stdc++.h>
using namespace std;

/*
* 省份数量
* @author fjl
* @date 2023-01-24 21:24:23
*/
//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    vector<vector<int>> edge={{1,1,0},{1,1,0},{0,0,1}};
   cout<<s.findCircleNum(edge);
}