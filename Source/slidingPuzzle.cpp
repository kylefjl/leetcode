#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std; //命名空间
#define uint16 wchar_t
#define uint32 unsigned int
#define uint8 unsigned char
#define int16 short
class Solution
{
private:
    vector<vector<int>> neighbor = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        int m = 2, n = 3;
        string start = "";
        string target = "123450";
        // 将 2x3 的数组转化成字符串
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                start.push_back(board[i][j] + '0');
            }
        }

        /******* BFS 算法框架开始 *******/
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);

        int step = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                string cur = q.front();
                q.pop();
                // 判断是否达到目标局面
                if (target == cur)
                {
                    return step;
                }
                // 找到数字 0 的索引
                int idx = 0;
                for (; cur[idx] != '0'; idx++)
                    ;
                // 将数字 0 和相邻的数字交换位置
                for (int adj : neighbor[idx])
                {
                    string new_board = cur;
                    swap(new_board[adj], new_board[idx]);
                    // 防止走回头路
                    if (!visited.count(new_board))
                    {
                        q.push(new_board);
                        visited.insert(new_board);
                    }
                }
            }
            step++;
        }
        return -1;
        /******* BFS 算法框架结束 *******/
    }
} ;
int main()
{
    vector<vector<int>> board = {{1, 2, 3}, {0, 4, 5}};
    Solution solution;
    int step = solution.slidingPuzzle(board);
    printf("step %d\n", step);
    system("pause");
    return 0;
}
