//一个酒店里有 n 个房间，这些房间用二维整数数组 rooms 表示，其中 rooms[i] = [roomIdi, sizei] 表示有一个房间号为 
//roomIdi 的房间且它的面积为 sizei 。每一个房间号 roomIdi 保证是 独一无二 的。 
//
// 同时给你 k 个查询，用二维数组 queries 表示，其中 queries[j] = [preferredj, minSizej] 。第 j 个查询的答
//案是满足如下条件的房间 id ： 
//
// 
// 房间的面积 至少 为 minSizej ，且 
// abs(id - preferredj) 的值 最小 ，其中 abs(x) 是 x 的绝对值。 
// 
//
// 如果差的绝对值有 相等 的，选择 最小 的 id 。如果 没有满足条件的房间 ，答案为 -1 。 
//
// 请你返回长度为 k 的数组 answer ，其中 answer[j] 为第 j 个查询的结果。 
//
// 
//
// 示例 1： 
//
// 
//输入：rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
//输出：[3,-1,3]
//解释：查询的答案如下：
//查询 [3,1] ：房间 3 的面积为 2 ，大于等于 1 ，且号码是最接近 3 的，为 abs(3 - 3) = 0 ，所以答案为 3 。
//查询 [3,3] ：没有房间的面积至少为 3 ，所以答案为 -1 。
//查询 [5,2] ：房间 3 的面积为 2 ，大于等于 2 ，且号码是最接近 5 的，为 abs(3 - 5) = 2 ，所以答案为 3 。 
//
// 示例 2： 
//
// 
//输入：rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], queries = [[2,3],[2,4],[2,5]]
//输出：[2,1,3]
//解释：查询的答案如下：
//查询 [2,3] ：房间 2 的面积为 3 ，大于等于 3 ，且号码是最接近的，为 abs(2 - 2) = 0 ，所以答案为 2 。
//查询 [2,4] ：房间 1 和 3 的面积都至少为 4 ，答案为 1 因为它房间编号更小。
//查询 [2,5] ：房间 3 是唯一面积大于等于 5 的，所以答案为 3 。 
//
// 
//
// 提示： 
//
// 
// n == rooms.length 
// 1 <= n <= 10⁵ 
// k == queries.length 
// 1 <= k <= 10⁴ 
// 1 <= roomIdi, preferredj <= 10⁷ 
// 1 <= sizei, minSizej <= 10⁷ 
// 
//
// Related Topics 数组 二分查找 排序 👍 38 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 最近的房间
* @author name
* @date 2023-04-07 23:00:04
*/
//leetcode submit region begin(Prohibit modification and deletion)
//
struct Event {
    // 事件的类型，0 表示房间，1 表示询问
    int type;
    // 房间的 size 或者询问的 minSize
    int size;
    // 房间的 roomId 或者询问的 preferred
    int id;
    // 房间在数组 room 中的原始编号或者询问在数组 queries 中的原始编号
    int origin;

    Event(int _type, int _size, int _id,int _origin): type(_type), size(_size), id(_id),origin(_origin){}

    // 自定义比较函数，按照事件的 size 降序排序
    // 如果 size 相同，优先考虑房间
    bool operator< (const Event& that) const {
        return size < that.size || (size == that.size && type > that.type);
    }
    bool operator> (const Event& that) const {
        return size > that.size || (size == that.size && type < that.type);
    }
};

class Solution {
public:
    //找到集合中离x最近的数，如果差的绝对值有相等的，选择最小的id 。如果没有满足条件，答案为 -1
    auto foundID(set<int>& data,int x)
    {
        auto low_it=data.lower_bound(x);//找到第一个大于等于x的数
        auto up_it=data.end();//
        if(low_it!=data.begin())
        {
            up_it = prev(low_it);//找到第一个小于x的数
        }
        if(low_it!=data.end()&&up_it!=data.end())//如果两个都找到了
            return (*low_it-x)>=(x-*up_it)?*up_it:*low_it;//返回差的绝对值最小的
        else if(low_it!=data.end())//如果只找到了low_it
            return *low_it;
        else if(up_it!=data.end())//如果只找到了up_it
            return *up_it;
        else return -1;//都没找到
    }
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries)
    {
        const int q_size=queries.size();
        const int r_size=rooms.size();
        vector<Event> e_sort;
        e_sort.reserve(q_size+r_size);//
        for (int i = 0; i < q_size; ++i)
        {
            e_sort.emplace_back(1,queries[i][1],queries[i][0],i);
        }
        for (int i = 0; i < r_size; ++i)
        {
            e_sort.emplace_back(0,rooms[i][1],rooms[i][0],i);
        }
        sort(e_sort.begin(),e_sort.end(), greater<>());
        set<int> data;
        vector<int> result(q_size);
        const int e_size=e_sort.size();
        for (int i = 0; i < e_size; ++i)
        {
            if(e_sort[i].type==0)//如果是房间
            {
                data.insert(e_sort[i].id);//插入房间id
            }
            else//如果是询问
            {
                result[e_sort[i].origin]=foundID(data,e_sort[i].id);//找到最近的房间id
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Solution s;
   vector<vector<int> > input1={{1,4},{2,3},{3,5},{4,1},{5,2}};
   vector<vector<int>> input2={{2,3},{2,4},{2,5}};
   auto result=s.closestRoom(input1,input2);


    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
}