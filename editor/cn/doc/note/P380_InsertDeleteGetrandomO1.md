# O(1) 时间插入、删除和获取随机元素

数组+哈希





```cc
class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));//随机种子
    }
    //插入 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false
    bool insert(int val) {
        if(list_idx.count(val))return false;
        list_idx[val]=list.size();//添加哈希键值
        list.push_back(val);//添加到数组
        return true;
    }
    //移除 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false
    bool remove(int val) {
        if(!list_idx.count(val))return false;
        list[list_idx[val]]=list.back();//交换val到数组最后一个
        list_idx[list.back()]=list_idx[val];//更新val的下标
        list_idx.erase(val);//删除哈希键值
        list.pop_back();//删除数组里面的值
        return true;
    }
    //随机访问
    int getRandom() {
        return list[rand()%list.size()];

    }
private:
    unordered_map<int,int> list_idx;//哈希存储数组下标，val作为键值
    vector<int> list;//数组，随机查找
};
```

