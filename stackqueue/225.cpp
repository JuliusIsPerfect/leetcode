#include <iostream>
#include <queue>

class MyStack {
public:
    std::queue<int> q;
    int qlen = 0;
    int qpop;
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        qlen = q.size();

        if (qlen == 1){
            qpop = q.front();
            q.pop();
        }
        else {
            qlen--;
            while(qlen--){
                q.push(q.front());
                q.pop();
            }
            qpop = q.front();
            q.pop();
        }

        return qpop;
    }
    
    int top() {
        this->pop();
        q.push(qpop);
        return qpop;
    }
    
    bool empty() {
        if (q.empty()) return true;
        return false;
    }
};

int main(){
    MyStack *myStack = new MyStack();
    myStack->push(1);
    myStack->push(2);
    myStack->top(); // 返回 2
    myStack->pop(); // 返回 2
    myStack->pop();
    myStack->empty(); // 返回 False


    std::cin.get();
}