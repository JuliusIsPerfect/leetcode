#include "iostream"
#include "list"
#include <cstddef>
#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
public:
    int capacity_;
    int size_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map_;
    std::list<std::pair<int, int>> list_;

    LRUCache(int capacity) :capacity_(capacity) {

    }
    
    int get(int key) {
        auto it = map_.find(key);
        if (it == map_.end()) return -1;

        list_.push_back(*it->second);
        list_.erase(it->second);
        // list_.splice(list_.end(), list_, it->second);
        map_[key] = std::prev(list_.end());

        return list_.back().second;
    }
    
    void put(int key, int value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            list_.erase(it->second);
        }
        list_.push_back({key, value});
        map_[key] = std::prev(list_.end());
        size_++;

        if (size_ > capacity_) {
            map_.erase(map_.find(list_.front().first));
            list_.pop_front();
            size_--;           
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    std::cout << "lRUCache->get(1): " << lRUCache->get(1) << std::endl;    // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    std::cout << "lRUCache->get(2): " << lRUCache->get(2) << std::endl;    // 返回 -1 (未找到)
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    std::cout << "lRUCache->get(1): " << lRUCache->get(1) << std::endl;    // 返回 -1 (未找到)
    lRUCache->get(3);    // 返回 3
    lRUCache->get(4);    // 返回 4

    std::cin.get();
}