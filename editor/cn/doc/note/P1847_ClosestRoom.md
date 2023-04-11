# 最近的房间

## 离线排序处理

> 引用官方题解

对于这种查找的任务来说，如果每次查找都需要按照minsize构建与树类似的结构则时间复杂度太大，可以选择将给定询问重新排序，那么是否可以使得问题更加容易解决？

可以将房间以及询问都看成一个「事件」，如果我们将这些「事件」按照大小（房间的 size 或者询问的 minSize）进行降序排序，那么：

- 如果我们遇到一个表示房间的「事件」，那么可以将该房间的 roomId 加入某一「数据结构」中；
- 如果我们遇到一个表示询问的「事件」，那么需要在「数据结构」中寻找与 preferred 最接近的 roomId

这样就只需要维护一个集合即可，避免了每次询问时遍历或为每个minisize建立集合的过程

我们使用「有序集合」`set`作为提示中的「数据结构」。

- 如果我们遇到一个表示房间的「事件」，那么将该该房间的roomId 加入「有序集合」中；
- 如果我们遇到一个表示询问的「事件」，那么答案即为「有序集合」中与询问的 preferred 最接近的那个 roomId。

> 在c++ 的 `set` API 中，提供了`lower_bound`，我们可以利用这些 API 找出「有序集合」中与 preferred 最接近的两个元素，其中一个小于 preferred，另一个大于等于preferred。通过比较这两个元素，我们即可得到该询问对应的答案。



```cc
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
```

