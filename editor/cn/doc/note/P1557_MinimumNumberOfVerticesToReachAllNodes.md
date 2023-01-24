可以到达所有点的最少点数目

找到入度为0的节点集合就行

```cc
class Solution {
public:
    vector<int> findSmallestSetOfVertices( const int n, vector<vector<int>>& edges) {
        vector<int> inDeegrees(n,0);//每个节点入度数
        vector<int> result;
        const int edge_size=edges.size();
        for (int i=0;i<edge_size;++i)++inDeegrees[edges[i][1]];
        result.reserve(n);
        for (int i=0;i<n;++i)
        {
            if(inDeegrees[i]==0)result.emplace_back(i);
        }
        return std::move(result);
    }
};
```

>执行耗时:232 ms,击败了72.26% 的C++用户
>内存消耗:91.6 MB,击败了89.42% 的C++用户