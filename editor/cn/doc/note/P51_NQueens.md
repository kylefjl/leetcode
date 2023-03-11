# N 皇后

## 基于位运算的回溯

>具体做法是，使用三个整数 *columns*、*diagonals*1 和 *diagonals*2 分别记录每一列以及两个方向的每条斜线上是否有皇后，每个整数有 *N* 个二进制位。棋盘的每一列对应每个整数的二进制表示中的一个数位，其中棋盘的最左列对应每个整数的最低二进制位，最右列对应每个整数的最高二进制位

参考 [N皇后 - N 皇后 - 力扣（LeetCode）](https://leetcode.cn/problems/n-queens/solution/nhuang-hou-by-leetcode-solution/)

```cc
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
```



