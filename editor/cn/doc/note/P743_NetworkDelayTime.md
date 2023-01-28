# 网络延迟时间

## Dijkstra

引用官方

>将所有节点分成两类：已确定从起点到当前点的最短路长度的节点，以及未确定从起点到当前点的最短路长度的节点（下面简称「未确定节点」和「已确定节点」）。
>
>每次从「未确定节点」中取一个与起点距离最短的点，将它归类为「已确定节点」，并用它「更新」从起点到其他所有「未确定节点」的距离。直到所有点都被归类为「已确定节点」。
>
>用节点 A「更新」节点 B 的意思是，用起点到节点 A 的最短路长度加上从节点 A 到节点 B 的边的长度，去比较起点到节点 B 的最短路长度，如果前者小于后者，就用前者更新后者。这种操作也被叫做「松弛」。
>
>这里暗含的信息是：每次选择「未确定节点」时，起点到它的最短路径的长度可以被确定。
>
>可以这样理解，因为我们已经用了每一个「已确定节点」更新过了当前节点，无需再次更新（因为**一个点不能多次到达**）。而当前节点已经是所有「未确定节点」中与起点距离最短的点，不可能被其它「未确定节点」更新。所以当前节点可以被归类为「已确定节点」。
>

```cc
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF=numeric_limits<int>::max()/2;
        const int edge_num=times.size();
        vector<vector<pair<int,int>>> edge(n);//邻接表
        forward_list<int> newPointList;//还未确定最小到达时间的节点序列
        for(int i=0;i<n;++i)newPointList.insert_after(newPointList.cbefore_begin(),i);
        for(int i=0;i<n;++i)edge[i].reserve(n);//预留空间
        for(int i=0;i<edge_num;++i)//创建邻接表
        {
            edge[times[i][0]-1].emplace_back(times[i][1]-1,times[i][2]);
        }
        vector<int> minTime(n,INF);//最小到达时间数组
        minTime[k-1]=0;//初始点到达时间为0
        int min=0,min_idx=0;//最小边的权重和序列号
        forward_list<int>::iterator min_it,last_it;//list 迭代器
        while(true)
        {
            min=INF;//初始给个最大值
            min_idx=-1;//给个不可能的序列
            last_it=newPointList.before_begin();
            for(auto beg=newPointList.begin();beg!=newPointList.end();++beg)
            {
                if(minTime[*beg]<min)
                {
                    min=minTime[*beg];
                    min_idx=*beg;
                    min_it=last_it;
                }
                last_it=beg;
            }
            if(min_idx==-1)//说明没有可以到达但未到达的点了
                break;//
            newPointList.erase_after(min_it);//在未连接列表内删除这次连接的节点
            for(auto j:edge[min_idx])//更新minTime
            {
                if(j.second+minTime[min_idx]<minTime[j.first])
                    minTime[j.first]=j.second+minTime[min_idx];
            }
        }//获取到达时间的最大值
        auto max_time=*max_element(minTime.begin(), minTime.end());
        return max_time==INF?-1: max_time ;//如果等于INF，则认为有不能到达的点，返回-1
    }
};
```

>执行耗时:88 ms,击败了86.19% 的C++用户
>内存消耗:36.9 MB,击败了61.38% 的C++用户



## Floyd

[所有节点对最短路径的Floyd算法：可以有负权边，但不能有负权回路](https://blog.csdn.net/qq_33726635/article/details/106572966)

复杂度为n^3 , 但是可以一次性求出所有顶点相互之间的最短距离和路径

```cc
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF=numeric_limits<int>::max()/2;
        const int edge_num=times.size();
        vector<vector<int>> d(n,vector<int>(n,INF));//邻接表
        for(int i=0;i<edge_num;++i)//初始化d，d[i][j]代表i到j的距离
        {
            d[times[i][0]-1][times[i][1]-1]=times[i][2];
        }
        for (int i = 0; i<n; ++i) d[i][i] = 0;//i到i的距离为0
        for (int m = 0; m < n; ++m){
            for (int i = 0; i<n; ++i){
                for (int j =0; j<n; ++j){//每次更新i经过k到j的距离
                    d[i][j] = min(d[i][j], d[i][m] + d[m][j]);
                }
            }
        }
        //获取到达时间的最大值
        auto max_time=*max_element(d[k-1].begin(), d[k-1].end());
        return max_time==INF?-1: max_time ;//如果等于INF，则认为有不能到达的点，返回-1
    }
};
```

>执行耗时:184 ms,击败了6.80% 的C++用户
>内存消耗:36.3 MB,击败了85.35% 的C++用户