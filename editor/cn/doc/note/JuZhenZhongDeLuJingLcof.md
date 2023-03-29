# 矩阵中的路径

## 回溯法





```cc
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m= board.size();
        const int n=board[0].size();
        const int length=word.size();//单词长度
        vis.resize(static_cast<const int> (m*n));//一维 m*n，默认false，未被使用
        return backrack(board,word,length,0,m,n,-1,-1);//回溯法
    }
//回溯法，board为字母矩阵，word字符串单词，idx为word在board中已经确定的个数，x,y为word第idx-1个字母在矩阵中的位置
    bool backrack(vector<vector<char>>& board, string& word,int len,int idx,int m,int n,int x,int y)
    {
        if(idx==len)//全部找到
        {
            return true;
        }
        if(idx==0)//如果是头一个，则矩阵中的任何位置只要相等都可以作为开始匹配的位置
        {
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if(board[i][j]==word[idx])
                    {
                        vis[i*n+j]=true;//标记当前位置的字母已经使用
                        if(backrack(board,word,len,idx+1,m,n,i,j))
                            return true;
                        vis[i*n+j]=false;//恢复
                    }
                }
            }
        }
        else{//在x,y的周围查找下一个匹配的字母
            //如果(x+1,y)为越界且未被使用过，判断是否匹配
            if(x+1<m&&!vis[(x+1)*n+y]&&board[x+1][y]== word[idx]){
                vis[(x+1)*n+y]=true;
                if(backrack(board,word,len,idx+1,m,n,x+1,y))
                    return true;
                vis[(x+1)*n+y]=false;
            }
            if(0<=x-1&&!vis[(x-1)*n+y]&&board[x-1][y]== word[idx]) {
                vis[(x-1)*n+y]=true;
                if(backrack(board,word,len,idx+1,m,n,x-1,y))
                    return true;
                vis[(x-1)*n+y]=false;

            }
            if(y+1<n&&!vis[x*n+(y+1)]&&board[x][y+1]== word[idx]){
                vis[x*n+(y+1)]=true;
                if(backrack(board,word,len,idx+1,m,n,x,y+1))
                    return true;
                vis[x*n+(y+1)]=false;
            }
            if(0<=y-1&&!vis[x*n+(y-1)]&&board[x][y-1]== word[idx]){
                vis[x*n+(y-1)]=true;
                if(backrack(board,word,len,idx+1,m,n,x,y-1))
                    return true;
                vis[x*n+(y-1)]=false;
            }
        }
        return false;
    }
private:
    vector<bool> vis;//标记是否已经使用过这个数字
};
```

>执行耗时:148 ms,击败了97.62% 的C++用户
>	内存消耗:6.2 MB,击败了29.96% 的C++用户