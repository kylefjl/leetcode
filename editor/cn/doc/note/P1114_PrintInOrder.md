# 按序打印

## 单独使用mutex

创建mutex 1管理first，second之间的关系

创建mutex 2管理second，third之间的关系

用两个互斥锁来阻塞 `second` 和 `third` 函数，分别在 `first` 和 `second` 执行结束后解锁

使用unique_lock来包装mutex

```cc
class Foo {
public:
    Foo():lk1(m1),lk2(m2){}

    void first(function<void()> printFirst) {
        printFirst();
        lk1.unlock();//打印完后解锁m1，让second()可以执行
    }

    void second(function<void()> printSecond) {

        {unique_lock<mutex> lk(m1);
        printSecond();}
        lk2.unlock();//打印完后解锁m2，让third()可以执行
    }

    void third(function<void()> printThird) {

        // printThird() outputs "third". Do not change or remove this line.
//        lk2.lock();//锁住m2，等待second()打印完
        {unique_lock<mutex> lk(m2);//检查m2是否被锁，如果被锁则说明second()还没执行，阻塞third()线程
        printThird();}
    }
protected:
    mutex m1,m2;
    unique_lock<mutex> lk1,lk2;
};
```

## mutex + condition_variable

条件变量用于在多线程环境中等待特定事件发生

```cc
class Foo {
public:
    Foo()= default;
    void first(function<void()> printFirst) {
        unique_lock<mutex> lk(mtx);
        cv.wait(lk,[this]{return k==0;});//等待k==0
        printFirst();
        k=1;
        cv.notify_all();//通知其他线程
    }
    void second(function<void()> printSecond) {
        unique_lock<mutex> lk(mtx);
        cv.wait(lk,[this]{return k==1;});//等待k==1
        printSecond();
        k=2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {

        unique_lock<mutex> lk(mtx);
        cv.wait(lk,[this]{return k==2;});//等待k==2
        printThird();
        k=0;
        cv.notify_all();//通知其他线程
    }
private:
    mutex mtx;//互斥量
    condition_variable cv;//条件变量
    int k=0;//
};
```

## 异步

异步操作是一种，在不需要等待被调用方返回结果之前，就让操作继续进行下去的方法。针对这道题可以使用基于 future/promise 的异步编程模型。

future 和 promise 起源于函数式编程，其目的是将值（future）和计算方式（promise）分离，使得 promise 可以异步地修改 future，从而提高代码的可读性，并减少通信延迟。

`std::future` 是用来获取异步操作结果的模板类；`std::packaged_task, std::promise, std::async` 都可以进行异步操作，并拥有一个 `std::future` 对象，用来存储它们所进行的异步操作返回或设置的值（或异常），这个值会在将来的某一个时间点，通过某种机制被修改后，保存在其对应的 std::future 对象中：

对于 `std::promise`，可以通过调用 `std::promise::set_value` 来设置值并通知 std::future 对象：
参考链接：https://leetcode.cn/problems/print-in-order/solution/c-hu-chi-suo-tiao-jian-bian-liang-xin-hao-liang-yi/

```cc
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
```





## 原子操作

**原子操作能够保证多个线程顺序访问，不会导致数据争用**

```cc
class Foo {
public:
    Foo()= default;
    void first(function<void()> printFirst) {
        printFirst();//
        a=true;
    }
    void second(function<void()> printSecond) {
        while (a==false)
            this_thread::sleep_for(chrono::milliseconds(1));
        printSecond();
       b=true;
    }

    void third(function<void()> printThird) {
        while (b==false)
            this_thread::sleep_for(chrono::milliseconds(1));
        printThird();
    }
private:
    std::atomic<bool> a{ false };//原子操作，对a的操作不会导致数据争用
    std::atomic<bool> b{ false };//原子操作
};
```

