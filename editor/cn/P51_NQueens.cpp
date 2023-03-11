//按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。 
//
// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。 
//
// 
// 
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
// 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[["Q"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 
//
// Related Topics 数组 回溯 👍 1632 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* N 皇后
* @author fjl
* @date 2023-02-10 19:08:54
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> solveNQueens(int n) {
        vector<int> queens(n,-1);//存储一种排列
        putQueen(queens,n,0,(1<<n)-1,(1<<n)-1,(1<<n)-1);
        return std::move(result);
    }
    //回溯法枚举所有可能，queens为已经确定的皇后位置，row为这一次需要确定的行数，colnums，diagonals1,diagonals2为代表列、对角线1、2是否已经存在皇后
    void putQueen(vector<int>& queens,int n,int row,unsigned int colnums,unsigned int diagonals1,unsigned int diagonals2 ){
        if(n==row)
        {
            result.push_back(generateBoard(queens,n));//转换成字符并添加到结果
            return;
        }//有效的
        unsigned  int validPos=colnums & diagonals1 & diagonals2;//二进制表示中后n位分别代表row行是否可以防止queen，为1代表可以放置
        unsigned int pos=validPos&(-validPos);//获得进制表示中的最低位的1和其之后的0
        while (pos)//如果没有位置可以放了，说明当前的摆放不行，返回再试
        {
            validPos=validPos&~pos;//将最低位的1置0，标记已经摆放过了
            queens[row]= log2(pos);//计算pos的位数，即queen摆放在第几个格子
            //递归调用，更新colnums，diagonals1,diagonals2
            //diagonals1&(~pos))>>1|(1<<(n-1)右移并使第n为置1   diagonals1&(~pos))>>1|(1<<(n-1)左移并补零
            putQueen(queens,n,row+1,colnums&(~pos),(diagonals1&(~pos))>>1|(1<<(n-1)),(diagonals2&(~pos))<<1|1);
            queens[row]=-1;//撤销
            pos=validPos&(-validPos);//更新pos，取新的最低位的1和其之后的0
        }
    }
//转换成字符
    vector<string> generateBoard(vector<int> &queens, int n)
    {
        auto board = vector<string>();
        board.reserve(n);
        string row = string(n, '.');
        for (int i = 0; i < n; ++i)
        {
            row[queens[i]] = 'Q';
            board.push_back(row);
            row[queens[i]] = '.';
        }
        return board;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   auto  result=s.solveNQueens(4);
}