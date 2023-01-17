# 有效的数独

## 数独

思路：先统计相同的数所在的位置，然后再对数在相同行、列、方格的出现的次数进行统计判断

```cc
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<std::pair<char,char>> num_pos[9]={};
        for(char i=0;i<9;++i)//先统计相同的数所在的位置
        {
            for (char j = 0; j <9 ; ++j)
            {//
                if(board[i][j]!='.') num_pos[board[i][j] - '1'].emplace_back(i, j);
            }
        }
        char count[3][3]={},count_i[9]={}, count_j[9]={};
        for(auto & board_po : num_pos)
        {
            for(auto item:board_po)
            {//统计数在相同行、列、方格的出现的次数,如果大于2则不符合规定
                if((count[item.first/3][item.second/3]+=1)==2) return false;
                if((count_i[item.first]+=1)==2)return false;
                if((count_j[item.second]+=1)==2) return false;
            }//清空，方便统计下一个数
            memset(count,0,sizeof(count));
            memset(count_i,0,sizeof(count_i));
            memset(count_j,0,sizeof(count_j));
        }
        return true;
    }
};
```

>执行耗时:12 ms,击败了93.59% 的C++用户
>内存消耗:17.9 MB,击败了31.46% 的C++用户



