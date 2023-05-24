//给你一个类： 
//
// 
//class FooBar {
//  public void foo() {
//    for (int i = 0; i < n; i++) {
//      print("foo");
//    }
//  }
//
//  public void bar() {
//    for (int i = 0; i < n; i++) {
//      print("bar");
//    }
//  }
//}
// 
//
// 两个不同的线程将会共用一个 FooBar 实例： 
//
// 
// 线程 A 将会调用 foo() 方法，而 
// 线程 B 将会调用 bar() 方法 
// 
//
// 请设计修改程序，以确保 "foobar" 被输出 n 次。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 1
//输出："foobar"
//解释：这里有两个线程被异步启动。其中一个调用 foo() 方法, 另一个调用 bar() 方法，"foobar" 将被输出一次。
// 
//
// 示例 2： 
//
// 
//输入：n = 2
//输出："foobarfoobar"
//解释："foobar" 将被输出两次。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 1000 
// 
//
// Related Topics 多线程 👍 183 👎 0

#include<bits/stdc++.h>
using namespace std;

/*
* 交替打印 FooBar
* @author fjl
* @date 2023-05-23 16:11:35
*/
//leetcode submit region begin(Prohibit modification and deletion)
class FooBar {
private:
    int n;
    mutex m1;
    condition_variable cv;
    atomic<int> k = 1;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++)
        {
            {
                unique_lock<mutex> lk(m1);
                cv.wait(lk, [this] { return k == 1; });
                // printFoo() outputs "foo". Do not change or remove this line.
                printFoo();
                k = 2;
            }
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++)
        {
            {
                unique_lock<mutex> lk(m1);
                cv.wait(lk, [this] { return k == 2; });
                printBar();
                k = 1;
            }
            cv.notify_one();
        }
    }
};

// 异步
//class FooBar {
//private:
//    int n;
//    promise<void> p1;// 用于控制foo
//    promise<void> p2;// 用于控制bar
//public:
//    FooBar(int n) {
//        this->n = n;
//        p1.set_value();// 初始化 p1 开始执行foo
//
//    }
//
//    void foo(function<void()> printFoo) {
//
//        for (int i = 0; i < n; i++)
//        {
//            p1.get_future().get();// 等待p1执行完毕
//            printFoo();
//            p1 = promise<void>();// 重置p1
//            p2.set_value();// 设置p2开始执行bar
//        }
//    }
//
//    void bar(function<void()> printBar) {
//
//        for (int i = 0; i < n; i++)
//        {
//            p2.get_future().get();// 等待p2执行完毕
//            printBar();//
//            p2 = promise<void>();// 重置p2
//            p1.set_value();// 设置p1开始执行foo
//
//        }
//    }
//};


//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    FooBar fooBar(10);
    thread t1(&FooBar::foo,&fooBar,[]{cout<<"foo";});
    thread t2(&FooBar::bar,&fooBar,[]{cout<<"bar";});
    t1.join();
    t2.join();

    return 0;
}