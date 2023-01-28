# 连接所有点的最小费用

## Prim

解题思路 参考：[yexiso](https://leetcode.cn/problems/min-cost-to-connect-all-points/solution/prim-and-kruskal-by-yexiso-c500/)

抽象出两个集合，集合 *V* 和集合 Vnew 

- 集合 *V* 保存未加入到最小生成树中的节点，最开始，图中所有节点都在集合 *V* 中
- 集合 Vnew 保存已经加入到最小生成树中的节点，如果一个节点加入到了最小生成树中，则将该节点加入到集合 Vnew 

> 说明 Vnew  即最小生成树

由于本题边数远大于点数，是一张稠密图，因此在运行时间上，枚举写法要快于优先级队列。

#### 枚举

```cc
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int points_num=points.size();
        forward_list<int> newPointList;//还未连接的节点序列
        for(int i=0;i<points_num;++i)newPointList.insert_after(newPointList.cbefore_begin(),i);
        vector<int> lowCost(points_num);//最短边
        for(int i=0;i<points_num;++i)lowCost[i]= ManDistance(points[0],points[i]);//第一个节点做初始点
        int min=0,min_idx=0;//最小边的权重和序列号
        forward_list<int>::iterator min_it,last_it;//list 迭代器
        int sum=0;//最终的权重和
        while(true)
        {
            min=numeric_limits<int>::max();//初始给个最大值
            min_idx=-1;//给个不可能的序列
            last_it=newPointList.before_begin();
            for(auto beg=newPointList.begin();beg!=newPointList.end();++beg)
            {
                if(lowCost[*beg]<=min)
                {
                    min=lowCost[*beg];
                    min_idx=*beg;
                    min_it=last_it;
                }
                last_it=beg;
            }
            if(min_idx==-1)//说明没有未连接的节点序列了
                break;//
            sum+=lowCost[min_idx];
            newPointList.erase_after(min_it);//在未连接列表内删除这次连接的节点
            int edge_value=0;
            for(auto j:newPointList)//更新lowcost
            {
                edge_value=ManDistance(points[min_idx],points[j]);
                if(edge_value<lowCost[j])
                    lowCost[j]=edge_value;
            }
        }
        return sum ;
    }
    inline int ManDistance( vector<int > & a, vector<int> & b )//曼哈顿距离
    {
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
};
```

>执行耗时:48 ms,击败了98.79% 的C++用户
>内存消耗:10.2 MB,击败了94.74% 的C++用户

#### 使用优先级序列

```cc
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int points_num=points.size();
        vector<bool> newPoint(points_num,true);//点序列，true代表还未连接
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> edge_queue;//边的优先级队列，小顶堆,默认先比较pair.first
        pair<int,int> min_edge;//最小边的权重和序列号
        int sum=0,n=0;//sum 最终的权重和  n 已经连接的点数
        edge_queue.emplace(0,0);
        while(!edge_queue.empty()&&n<points_num)
        {
            min_edge=edge_queue.top();//访问顶层
            edge_queue.pop();//弹出
            if(!newPoint[min_edge.second])//如果是访问过的点，直接下一次循环
                continue;
            ++n;//如果不是访问过的，把这个点的边加入edge_queue
            sum+= min_edge.first;
            newPoint[min_edge.second]=false;
            for(int i=0;i<points_num;++i)
            {
                if(newPoint[i])
                {//加入edge_queue
                    edge_queue.emplace(ManDistance(points[min_edge.second],points[i]),i);
                }
            }
        }
        return sum ;
    }
    static inline int ManDistance( vector<int >& a, vector<int>& b )//曼哈顿距离
    {
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
};
```

>执行耗时:144 ms,击败了79.81% 的C++用户
>内存消耗:41.1 MB,击败了75.84% 的C++用户

