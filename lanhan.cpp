#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <memory>
/*
    懒汉式单例模式中，单例对象在第一次被访问时才被创建。
    需要在 GetInstance() 方法中加锁，以确保只有一个线程可以创建实例。
*/
class Singleton {
public:
    static Singleton &GetInstance() {
        if (!instance_) {
            mutex_.lock();
            if (!instance_) {
                instance_ = new Singleton();
            }
            mutex_.unlock();
        }
        return *instance_;
    }

    class CGarbo 
    {
    public:
        ~CGarbo()
        {
            if(Singleton::instance_) 
                delete Singleton::instance_;
        }
    };

    static CGarbo Garbo; // 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象


private:
    Singleton() {} // private constructor
    Singleton(Singleton const&) = delete; // disable copy constructor
    void operator=(Singleton const&) = delete; // disable assignment operator

    // static Singleton* instance_;
    static Singleton* instance_;
    static std::mutex mutex_;
};

Singleton* Singleton::instance_ = nullptr;
std::mutex Singleton::mutex_;
Singleton::CGarbo Garbo;

void thread_func() {
    //调用 Singleton::getInstance() 函数来获取单例对象的引用
    Singleton& singleton = Singleton::GetInstance();
    printf("Singleton instance address: %p\n", &singleton);
}

int main() {
    std::vector<std::thread> threads;
    const int num_threads = 3;

    for (int i = 0; i < num_threads; ++i) {
        //threads将 `thread_func` 函数作为线程函数，创建多个线程并启动它们：
        threads.emplace_back(thread_func);
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
