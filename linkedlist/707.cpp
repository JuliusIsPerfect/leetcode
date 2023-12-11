#include <iostream>


class MyLinkedList {
public:
    int val, len = 0;
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };
    LinkedNode* head;
    MyLinkedList() {
        head = new LinkedNode(0);
    }
    
    int get(int index) {
        if (index < 0 || index > len - 1) return -1;
        LinkedNode* p = head;
        p = head;
        for (int i = 0;i <= index; i++){
            p = p->next;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* p = new LinkedNode(val);
        p->next = head->next;
        head->next = p;
        // head = p;
        len++;
    }
    
    void addAtTail(int val) {
        LinkedNode* p = head;
        for (int i = 0;i < len; i++){
            p = p->next;
        }
        LinkedNode* tail = new LinkedNode(val);
        p->next = tail;
        len++;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0){
            LinkedNode* p = new LinkedNode(val);
            p->next = head->next;
            head = p;
        }
        if (index < 0 || index > len) return;
        LinkedNode* p = head;
        for (int i = 0;i < index; i++){
            p = p->next;
        }
        LinkedNode* p1 = new LinkedNode(val);
        p1->next = p->next;
        p->next = p1;
        len++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= len) return;

        if (index == 0) {
            head->next = head->next->next;
            len--;
            return;
        }
        LinkedNode* p = head;
        for (int i = 0;i < index; i++){
            p = p->next;
        }
        p->next = p->next->next;
        len--;
    }
    
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){
    MyLinkedList* myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    myLinkedList->addAtTail(3);
    myLinkedList->addAtIndex(1, 2);    // 链表变为 1->2->3
    myLinkedList->get(1);              // 返回 2
    myLinkedList->deleteAtIndex(1);    // 现在，链表变为 1->3
    myLinkedList->get(1);              // 返回 3
    myLinkedList->get(3);
    myLinkedList->deleteAtIndex(3);
    myLinkedList->deleteAtIndex(0);
    myLinkedList->get(0);
    myLinkedList->deleteAtIndex(0);
    myLinkedList->get(0);     
    std::cin.get();
}