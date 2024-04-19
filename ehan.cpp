#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

/*
    在饿汉式单例模式中，单例对象在程序启动时就被创建。
    C++11 中，局部静态变量的初始化是线程安全的，编译器会使用互斥锁来保证只有一个线程可以进行初始化操作，
    其他线程会被阻塞等待初始化完成。
    
    在 C++11 之前，需要使用其他机制来保证线程安全，
    比如使用懒汉式单例模式，并使用互斥锁等同步机制来避免竞态条件问题。
*/
class Singleton {
public:
    //获取单例对象的引用
    static Singleton& GetInstance() {
        //使用了一个静态局部变量 instance 来存储单例对象，这保证了它只被初始化一次
        //这个局部变量是在第一次调用 GetInstance() 函数时初始化的

        return instance_;
    }

private:
    Singleton() = default;
    ~Singleton() = default;

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton instance_;
};

Singleton Singleton::instance_ = Singleton();  // 可以编译运行

void thread_func() {
    //调用 Singleton::getInstance() 函数来获取单例对象的引用
    Singleton& singleton = Singleton::GetInstance();
    printf("Singleton instance address: %p\n", &singleton);
}

int main() {
    std::vector<std::thread> threads;
    const int num_threads = 10;

    for (int i = 0; i < num_threads; ++i) {
        //threads将 `thread_func` 函数作为线程函数，创建多个线程并启动它们：
        threads.emplace_back(thread_func);
    }

    for (auto& t : threads) {
        t.join();
    }

    // std::cin.get();
    return 0;
}
