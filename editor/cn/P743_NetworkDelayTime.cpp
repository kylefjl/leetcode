//有 n 个网络节点，标记为 1 到 n。 
//
// 给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， 
//wi 是一个信号从源节点传递到目标节点的时间。 
//
// 现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：times = [[1,2,1]], n = 2, k = 1
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：times = [[1,2,1]], n = 2, k = 2
//输出：-1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= n <= 100 
// 1 <= times.length <= 6000 
// times[i].length == 3 
// 1 <= ui, vi <= n 
// ui != vi 
// 0 <= wi <= 100 
// 所有 (ui, vi) 对都 互不相同（即，不含重复边） 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 图 最短路 堆（优先队列） 👍 625 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 网络延迟时间
* @author fjl
* @date 2023-01-27 22:37:55
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public://floyd 算法
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
//leetcode submit region end(Prohibit modification and deletion)

// -----------------------Dijkstra---------------------------
//class Solution {
//public:
//    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//        const int INF=numeric_limits<int>::max()/2;
//        const int edge_num=times.size();
//        vector<vector<pair<int,int>>> edge(n);//邻接表
//        forward_list<int> newPointList;//还未确定最小到达时间的节点序列
//        for(int i=0;i<n;++i)newPointList.insert_after(newPointList.cbefore_begin(),i);
//        for(int i=0;i<n;++i)edge[i].reserve(n);//预留空间
//        for(int i=0;i<edge_num;++i)//创建邻接表
//        {
//            edge[times[i][0]-1].emplace_back(times[i][1]-1,times[i][2]);
//        }
//        vector<int> minTime(n,INF);//最小到达时间数组
//        minTime[k-1]=0;//初始点到达时间为0
//        int min=0,min_idx=0;//最小边的权重和序列号
//        forward_list<int>::iterator min_it,last_it;//list 迭代器
//        while(true)
//        {
//            min=INF;//初始给个最大值
//            min_idx=-1;//给个不可能的序列
//            last_it=newPointList.before_begin();
//            for(auto beg=newPointList.begin();beg!=newPointList.end();++beg)
//            {
//                if(minTime[*beg]<min)
//                {
//                    min=minTime[*beg];
//                    min_idx=*beg;
//                    min_it=last_it;
//                }
//                last_it=beg;
//            }
//            if(min_idx==-1)//说明没有可以到达但未到达的点了
//                break;//
//            newPointList.erase_after(min_it);//在未连接列表内删除这次连接的节点
//            for(auto j:edge[min_idx])//更新minTime
//            {
//                if(j.second+minTime[min_idx]<minTime[j.first])
//                    minTime[j.first]=j.second+minTime[min_idx];
//            }
//        }//获取到达时间的最大值
//        auto max_time=*max_element(minTime.begin(), minTime.end());
//        return max_time==INF?-1: max_time ;//如果等于INF，则认为有不能到达的点，返回-1
//    }
//};

int main()
{
   Solution s;
   vector<vector<int>> times={{2,1,1},{2,3,1},{3,4,1}};
 std::cout<<  s.networkDelayTime(times,4,2);
}