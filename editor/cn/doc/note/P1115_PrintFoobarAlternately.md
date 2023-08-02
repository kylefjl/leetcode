# 交替打印 FooBar

## mutex + condition_variable 

```cc
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
```







## 异步

```cc
class FooBar {
private:
    int n;
    promise<void> p1;// 用于控制foo
    promise<void> p2;// 用于控制bar
public:
    FooBar(int n) {
        this->n = n;
        p1.set_value();// 初始化 p1 开始执行foo

    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++)
        {
            p1.get_future().get();// 等待p1执行完毕
            printFoo();
            p1 = promise<void>();// 重置p1,   promise<void> p1 只能使用一次
            p2.set_value();// 设置p2开始执行bar
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++)
        {
            p2.get_future().get();// 等待p2执行完毕
            printBar();//
            p2 = promise<void>();// 重置p2
            p1.set_value();// 设置p1开始执行foo

        }
    }
};
```

