//在二维网格 grid 上，有 4 种类型的方格： 
//
// 
// 1 表示起始方格。且只有一个起始方格。 
// 2 表示结束方格，且只有一个结束方格。 
// 0 表示我们可以走过的空方格。 
// -1 表示我们无法跨越的障碍。 
// 
//
// 返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目。 
//
// 每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格。 
//
// 
//
// 示例 1： 
//
// 输入：[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
//输出：2
//解释：我们有以下两条路径：
//1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
//2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2) 
//
// 示例 2： 
//
// 输入：[[1,0,0,0],[0,0,0,0],[0,0,0,2]]
//输出：4
//解释：我们有以下四条路径： 
//1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
//2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
//3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
//4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3) 
//
// 示例 3： 
//
// 输入：[[0,1],[2,0]]
//输出：0
//解释：
//没有一条路能完全穿过每一个空的方格一次。
//请注意，起始和结束方格可以位于网格中的任意位置。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= grid.length * grid[0].length <= 20 
// 
//
// Related Topics 位运算 数组 回溯 矩阵 👍 354 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 不同路径 III
* @author fjl
* @date 2024-05-05 23:04:26
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        grid_row=grid.size();
        grid_col=grid[0].size();
        vector<pair<int,int>> path;
        vector<vector<int>> view_history(grid_row,vector<int>(grid_col,0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)len++;
                if(grid[i][j]==1)start={i,j};
                if(grid[i][j]==2)end={i,j};
                if (grid[i][j]==-1)view_history[i][j]=1;
            }
        }
        view_history[start.first][start.second]=1;
        backrack(grid,view_history,start,path);
        return path_num;
    }
    inline bool is_value(pair<int,int> next)
    {
        return next.first>=0&&next.first<grid_row&&next.second>=0&&next.second<grid_col;
    }
    void backrack(vector<vector<int>>& grid,vector<vector<int>>& view_history,pair<int,int>start,vector<pair<int,int>>& path)
    {
        if(path.size()==(len+1))//包括终点
        {
            if (grid[start.first][start.second]==2)
                path_num++;
            return;
        }
        vector<pair<int,int>> steps{{-1,0},{0,1},{1,0},{0,-1}};
        for (auto & step:steps)
        {

            pair<int,int> next={start.first+step.first,start.second+step.second};
            if(is_value(next)&&view_history[next.first][next.second]==0)
            {
                path.push_back(next);
                view_history[next.first][next.second]=1;
                backrack(grid,view_history,next,path);
                view_history[next.first][next.second]=0;
                path.pop_back();
            }
        }



    }
    int path_num=0;
    int grid_col=0;
    int grid_row=0;
    int len=0;
    pair<int,int> start;
    pair<int,int> end;

};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
    vector<vector<int>> grid={{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    // 1 0 0 0
    // 0 0 0 0
    // 0 0 2 -1
    cout<<s.uniquePathsIII(grid)<<endl;


}