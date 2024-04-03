#include <iostream>
#include <stack>

class MinStack {
public:
    std::stack<int> normal_stack{};
    std::stack<int> stck{};
    std::stack<int> backup{};

    MinStack() {

    }
    
    void push(int val) {
        normal_stack.emplace(val);

        while (!stck.empty() && stck.top() < val) {
            backup.emplace(stck.top());
            stck.pop();
        }
        stck.push(val);
        while (!backup.empty()) {
            stck.emplace(backup.top());
            backup.pop();
        }
    }
    
    void pop() {
        int val = normal_stack.top();
        normal_stack.pop();
        while (stck.top() != val) {
            backup.emplace(stck.top());
            stck.pop();
        }
        stck.pop();
        while (!backup.empty()) {
            stck.emplace(backup.top());
            backup.pop();
        }
    }
    
    int top() {
        return normal_stack.top();
    }
    
    int getMin() {
        return stck.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */