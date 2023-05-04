//中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。 
//
// 
// 例如 arr = [2,3,4] 的中位数是 3 。 
// 例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。 
// 
//
// 实现 MedianFinder 类: 
//
// 
// MedianFinder() 初始化 MedianFinder 对象。 
// void addNum(int num) 将数据流中的整数 num 添加到数据结构中。 
// double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10⁻⁵ 以内的答案将被接受。 
// 
//
// 示例 1： 
//
// 
//输入
//["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
//[[], [1], [2], [], [3], []]
//输出
//[null, null, null, 1.5, null, 2.0]
//
//解释
//MedianFinder medianFinder = new MedianFinder();
//medianFinder.addNum(1);    // arr = [1]
//medianFinder.addNum(2);    // arr = [1, 2]
//medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
//medianFinder.addNum(3);    // arr[1, 2, 3]
//medianFinder.findMedian(); // return 2.0 
//
// 提示: 
//
// 
// -10⁵ <= num <= 10⁵ 
// 在调用 findMedian 之前，数据结构中至少有一个元素 
// 最多 5 * 10⁴ 次调用 addNum 和 findMedian 
// 
//
// Related Topics 设计 双指针 数据流 排序 堆（优先队列） 👍 817 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 数据流的中位数
* @author name
* @date 2023-04-18 11:26:33
*/

//leetcode submit region begin(Prohibit modification and deletion)

//template <typename T>
//有序集合 + 双指针
//class MedianFinder {
//public:
//    MedianFinder()=default;
//    void addNum(int num) {
//        nums.insert(num);//插入,自动排序 multiset 特性，insert 插入不会使迭代器失效，而且如果num相等的数已经存在，则num会安排到此数++的位置
//        if(nums.size()==1)//
//        {
//            left=nums.begin();//指向第一个元素
//            right=nums.begin();//指向第一个元素
//        }
//        else if(nums.size()%2==0)//插入后为偶数，说明此前left和right指向同一个数
//        {
//            if(num<*left)//插入的数比左边的小
//            {
//                left--;//左边的指针左移
//            }
//            else if(num>*right)//插入的数比右边的大
//            {
//                ++right;
//            }
//            else//如果与left和right相等
//            {
//                right++;//right指向新填入的数
//            }
//        }
//        else//插入后为奇数，说明此前left和right指向两个数（这两个数是有可能相等的）
//        {
//            if(num<*left)//小于left，此数只能插入到左边
//            {
//                --right;//right左移，与left指向一个数
//            }
//            else if(num>=*right)//大于等于right，此数只能插入到右边
//            {
//                ++left;//left右移，与right指向一个数
//            }
//            else//大于等于left，小于right，此数只能插入到rigth和left中间
//            {
//                ++left;//同时移动left，right，指向插入的数
//                --right;
//            }
//
//        }
//
//    }
//    double findMedian() {
//        return (*left+*right)/2.0;//返回中位数
//    }
//    multiset<int> nums;
//    multiset<int>::iterator left,right;
//
//};

//大小堆 优先队列
class MedianFinder {
public:
    MedianFinder() {
    }

    void addNum(int num) {
        if(queue_big.empty()||num<queue_big.top())//如果为空或者小于大顶堆的堆顶
        {
            queue_big.push(num);//插入大顶堆
            if(queue_big.size()>queue_small.size()+1)//如果大顶堆的元素多于小顶堆的元素
            {
                queue_small.push(queue_big.top());//将大顶堆的堆顶元素插入小顶堆
                queue_big.pop();//删除大顶堆的堆顶元素
            }

        }
        else//如果大于大顶堆的堆顶
        {
            queue_small.push(num);//插入小顶堆
            if(queue_small.size()>queue_big.size()+1)//如果小顶堆的元素多于大顶堆的元素
            {
                queue_big.push(queue_small.top());//将小顶堆的堆顶元素插入大顶堆
                queue_small.pop();//删除小顶堆的堆顶元素
            }
        }
    }
    double findMedian() {
        if(queue_big.size()==queue_small.size())//如果两个堆的元素相等
        {
            return static_cast<double>(queue_big.top()+queue_small.top())/2.0;//返回两个堆顶元素的平均值
        }
        else if (queue_big.size()>queue_small.size())//如果大顶堆的元素多
        {
            return queue_big.top();
        }
        else
        {
            return queue_small.top();
        }
    }

    vector<int> nums;
    priority_queue<int,vector<int>,greater<>> queue_small;//小顶堆
    priority_queue<int> queue_big;//大顶堆

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    MedianFinder s;

    //	测试用例:["MedianFinder","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian"]
    //[[],[6],[],[10],[],[2],[],[6],[],[5],[],[0],[],[6],[],[3],[],[1],[],[0],[],[0],[]]
    s.addNum(40);
    cout<<s.findMedian()<<endl;
    s.addNum(12);
    cout<<s.findMedian()<<endl;
    s.addNum(16);
    cout<<s.findMedian()<<endl;

//    s.addNum(6);
//    cout<<s.findMedian()<<endl;
//    s.addNum(5);
//    cout<<s.findMedian()<<endl;
//    s.addNum(0);
//    cout<<s.findMedian()<<endl;
//    s.addNum(6);
//    cout<<s.findMedian()<<endl;
//    s.addNum(3);
//    cout<<s.findMedian()<<endl;
//    s.addNum(1);
//    cout<<s.findMedian()<<endl;
//    s.addNum(0);
//    cout<<s.findMedian()<<endl;
//    s.addNum(0);
//    cout<<s.findMedian()<<endl;

//    s.addNum(1);
//    s.addNum(2);
//
//    cout<<s.findMedian()<<endl;
//    s.addNum(3);
//    cout<<s.findMedian()<<endl;

}