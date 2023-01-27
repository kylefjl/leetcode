//给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。 
//
// 连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 
//val 的绝对值。 
//
// 请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
//输出：20
//解释：
//
//我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
//注意到任意两个点之间只有唯一一条路径互相到达。
// 
//
// 示例 2： 
//
// 
//输入：points = [[3,12],[-2,5],[-4,1]]
//输出：18
// 
//
// 示例 3： 
//
// 
//输入：points = [[0,0],[1,1],[1,0],[-1,1]]
//输出：4
// 
//
// 示例 4： 
//
// 
//输入：points = [[-1000000,-1000000],[1000000,1000000]]
//输出：4000000
// 
//
// 示例 5： 
//
// 
//输入：points = [[0,0]]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= points.length <= 1000 
// -10⁶ <= xi, yi <= 10⁶ 
// 所有点 (xi, yi) 两两不同。 
// 
//
// Related Topics 并查集 图 数组 最小生成树 👍 260 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 连接所有点的最小费用
* @author fjl
* @date 2023-01-26 12:04:58
*/
//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    int minCostConnectPoints(vector<vector<int>>& points) {
//        const int points_num=points.size();
//        forward_list<int> newPointList;//还未连接的节点序列
//        for(int i=0;i<points_num;++i)newPointList.insert_after(newPointList.cbefore_begin(),i);
//        vector<int> lowCost(points_num);//最短边
//        for(int i=0;i<points_num;++i)lowCost[i]= ManDistance(points[0],points[i]);//第一个节点做初始点
//        int min=0,min_idx=0;//最小边的权重和序列号
//        forward_list<int>::iterator min_it,last_it;//list 迭代器
//        int sum=0;//最终的权重和
//        while(true)
//        {
//            min=numeric_limits<int>::max();//初始给个最大值
//            min_idx=-1;//给个不可能的序列
//            last_it=newPointList.before_begin();
//            for(auto beg=newPointList.begin();beg!=newPointList.end();++beg)
//            {
//                if(lowCost[*beg]<=min)
//                {
//                    min=lowCost[*beg];
//                    min_idx=*beg;
//                    min_it=last_it;
//                }
//                last_it=beg;
//            }
//            if(min_idx==-1)//说明没有未连接的节点序列了
//                break;//
//            sum+=lowCost[min_idx];
//            newPointList.erase_after(min_it);//在未连接列表内删除这次连接的节点
//            int edge_value=0;
//            for(auto j:newPointList)//更新lowcost
//            {
//                edge_value=ManDistance(points[min_idx],points[j]);
//                if(edge_value<lowCost[j]) lowCost[j]=edge_value;
//            }
//        }
//        return sum ;
//    }
//    inline int ManDistance( vector<int > & a, vector<int> & b )//曼哈顿距离
//    {
//        return abs(a[0]-b[0])+abs(a[1]-b[1]);
//    }
//};

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
//leetcode submit region end(Prohibit modification and deletion)



int main()
{
    Solution s;
    vector<vector<int>> points={{0,0},{2,2},{3,10},{5,2},{7,0}};
    std::cout<<s.minCostConnectPoints(points);

}