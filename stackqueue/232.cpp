#include <iostream>
#include <stack>

class MyQueue {
public:
    std::stack<int> stin,stout;
    int p;
    MyQueue() {

    }
    
    void push(int x) {
        stin.push(x);
    }
    
    int pop() {
        if (stout.empty()){
            while (!stin.empty()){
                stout.push(stin.top());
                stin.pop();
            }
            
        }

        p = stout.top();
        stout.pop();
        return p;
    }
    
    int peek() {
        if (stout.empty()){
            while (!stin.empty()){
                stout.push(stin.top());
                stin.pop();
            }
        }
        p = stout.top();
        return p;
    }
    
    bool empty() {
        if (stin.empty() && stout.empty()) return true;
        return false;
    }
};

int main(){
    MyQueue *myQueue = new MyQueue();
    myQueue->push(1); // queue is: [1]
    myQueue->push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue->peek(); // return 1
    myQueue->pop(); // return 1, queue is [2]
    myQueue->empty(); // return false



    std::cin.get();
}