//给你一个类： 
//
// 
//public class Foo {
//  public void first() { print("first"); }
//  public void second() { print("second"); }
//  public void third() { print("third"); }
//} 
//
// 三个不同的线程 A、B、C 将会共用一个 Foo 实例。 
//
// 
// 线程 A 将会调用 first() 方法 
// 线程 B 将会调用 second() 方法 
// 线程 C 将会调用 third() 方法 
// 
//
// 请设计修改程序，以确保 second() 方法在 first() 方法之后被执行，third() 方法在 second() 方法之后被执行。 
//
// 提示： 
//
// 
// 尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。 
// 你看到的输入格式主要是为了确保测试的全面性。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出："firstsecondthird"
//解释：
//有三个线程会被异步启动。输入 [1,2,3] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 second() 方法，线程 C 将会调用 
//third() 方法。正确的输出是 "firstsecondthird"。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,3,2]
//输出："firstsecondthird"
//解释：
//输入 [1,3,2] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 third() 方法，线程 C 将会调用 second() 方法。正
//确的输出是 "firstsecondthird"。 
//
// 
//
// 
// 
//提示：
//
// 
// nums 是 [1, 2, 3] 的一组排列 
// 
//
// Related Topics 多线程 👍 470 👎 0

#include<bits/stdc++.h>
//#include <semaphore.h>
#include <pthread.h>

using namespace std;

/*
* 按序打印
* @author fjl
* @date 2023-05-18 15:59:04
*/
//leetcode submit region begin(Prohibit modification and deletion)
//mutex 方法
//class Foo {
//public:
//    Foo():lk1(m1),lk2(m2){}
//
//    void first(function<void()> printFirst) {
//
//        // printFirst() outputs "first". Do not change or remove this line.
//        printFirst();
//        lk1.unlock();//打印完后解锁m1，让second()可以执行
//    }
//
//    void second(function<void()> printSecond) {
//
//        // printSecond() outputs "second". Do not change or remove this line.
////        lk1.lock();//锁住m1，等待first()打印完
//        {unique_lock<mutex> lk(m1);
//        printSecond();}
//        lk2.unlock();//打印完后解锁m2，让third()可以执行
//    }
//
//    void third(function<void()> printThird) {
//
//        // printThird() outputs "third". Do not change or remove this line.
////        lk2.lock();//锁住m2，等待second()打印完
//        {unique_lock<mutex> lk(m2);//检查m2是否被锁，如果被锁则说明second()还没执行，阻塞third()线程
//        printThird();}
//    }
//protected:
//    mutex m1,m2;
//    unique_lock<mutex> lk1,lk2;
////    condition_variable cv1,cv2;
////    int count=0;
//};
//mutex + condition_variable
//class Foo {
//public:
//    Foo()= default;
//    void first(function<void()> printFirst) {
//        unique_lock<mutex> lk(mtx);
//        cv.wait(lk,[this]{return k==0;});//等待k==0
//        printFirst();
//        k=1;
//        cv.notify_all();//通知其他线程
//    }
//    void second(function<void()> printSecond) {
//        unique_lock<mutex> lk(mtx);
//        cv.wait(lk,[this]{return k==1;});//等待k==1
//        printSecond();
//        k=2;
//        cv.notify_all();
//    }
//
//    void third(function<void()> printThird) {
//
//        unique_lock<mutex> lk(mtx);
//        cv.wait(lk,[this]{return k==2;});//等待k==2
//        printThird();
//        k=0;
//        cv.notify_all();//通知其他线程
//    }
//private:
//    mutex mtx;//互斥量
//    condition_variable cv;//条件变量
//    int k=0;//
//};
// TODO 异步编程模型
// 原子操作
//class Foo {
//public:
//    Foo()= default;
//    void first(function<void()> printFirst) {
//        printFirst();//
//        a=true;
//    }
//    void second(function<void()> printSecond) {
//        while (a==false)
//            this_thread::sleep_for(chrono::milliseconds(1));
//        printSecond();
//       b=true;
//    }
//
//    void third(function<void()> printThird) {
//        while (b==false)
//            this_thread::sleep_for(chrono::milliseconds(1));
//        printThird();
//    }
//private:
//    std::atomic<bool> a{ false };//原子操作，对a的操作不会导致数据争用
//    std::atomic<bool> b{ false };//原子操作
//};
class Foo {
    promise<void> pro1, pro2;//promise对象

public:
    void first(function<void()> printFirst) {
        printFirst();
        pro1.set_value();//设置共享状态为就绪
    }

    void second(function<void()> printSecond) {
        pro1.get_future().wait();//等待就绪
        printSecond();
        pro2.set_value();//设置共享状态为就绪
    }

    void third(function<void()> printThird) {
        pro2.get_future().wait();//等待就绪
        printThird();//打印
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
   Foo s;
   std::thread t1(&Foo::first,&s,[](){cout<<"first"<<endl;});
    std::thread t2(&Foo::second,&s,[](){cout<<"second"<<endl;});
    std::thread t3(&Foo::third,&s,[](){cout<<"third"<<endl;});
    t1.join();
    t2.join();
    t3.join();
}