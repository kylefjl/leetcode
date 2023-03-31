//实现RandomizedSet 类： 
//
// 
// 
// 
// RandomizedSet() 初始化 RandomizedSet 对象 
// bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。 
// bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。 
// int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。 
// 
// 
// 
//
// 你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。 
//
// 
//
// 示例： 
//
// 
//输入
//["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", 
//"insert", "getRandom"]
//[[], [1], [2], [2], [], [1], [2], []]
//输出
//[null, true, false, true, 2, true, false, 2]
//
//解释
//RandomizedSet randomizedSet = new RandomizedSet();
//randomizedSet.insert(1); // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
//randomizedSet.remove(2); // 返回 false ，表示集合中不存在 2 。
//randomizedSet.insert(2); // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
//randomizedSet.getRandom(); // getRandom 应随机返回 1 或 2 。
//randomizedSet.remove(1); // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
//randomizedSet.insert(2); // 2 已在集合中，所以返回 false 。
//randomizedSet.getRandom(); // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
// 
//
// 
//
// 提示： 
//
// 
// -2³¹ <= val <= 2³¹ - 1 
// 最多调用 insert、remove 和 getRandom 函数 2 * 10⁵ 次 
// 在调用 getRandom 方法时，数据结构中 至少存在一个 元素。 
// 
//
// Related Topics 设计 数组 哈希表 数学 随机化 👍 654 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* O(1) 时间插入、删除和获取随机元素
* @author name
* @date 2023-03-29 18:44:43
*/
//leetcode submit region begin(Prohibit modification and deletion)
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

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
     RandomizedSet* obj = new RandomizedSet();
    cout<<obj->insert(3)<<' ';
    cout<<obj->remove(3)<<' ';
     cout<<obj->remove(0)<<' ';
    cout<<obj->insert(3)<<' ';

}