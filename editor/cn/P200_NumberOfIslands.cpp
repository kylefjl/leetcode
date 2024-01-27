 //给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 2291 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 岛屿数量
* @author fjl
* @date 2023-09-12 16:11:25
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
    int numIslands(vector<vector<char>>& grid) {
        int num_one=0;//记录1的个数
        vector <pair<int,int>> islands_grid_pos; //记录1的位置
        vector<vector<int>> grid_idx(grid.size(),vector<int>(grid[0].size(),-1));//记录1的位置对应的下标
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]=='1')
                {
                    islands_grid_pos.push_back({i,j});
                    grid_idx[i][j]=num_one;
                    ++num_one;
                }
            }
        }
        UnionFind uf(num_one);//初始化并查集 传入集合数 也就是1的个数
        int r=0,c=0;
        for(int i=0;i<num_one;++i)//遍历1
        {
            r=islands_grid_pos[i].first;//获取1的位置
            c=islands_grid_pos[i].second;//获取1的位置
            if (r - 1 >= 0 && grid[r-1][c] == '1') uf.merge(grid_idx[r - 1][c],i);//如果上面是1,合并
            if (r + 1 < grid.size() && grid[r+1][c] == '1') uf.merge(grid_idx[r + 1][c],i);//如果下面是1,合并
            if (c - 1 >= 0 && grid[r][c-1] == '1') uf.merge( grid_idx[r ][c-1],i);//如果左边是1,合并
            if (c + 1 < grid[0].size() && grid[r][c+1] == '1')uf.merge(grid_idx[r ][c+1],i);
        }
        return uf.getsize();//返回集合数
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    vector<vector<char>> grid={{'1','1','1','1','0'},
                               {'1','1','0','1','0'},
                               {'1','1','0','0','0'},
                               {'0','0','0','0','0'}};
    cout<<s.numIslands(grid);
}