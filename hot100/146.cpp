#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>

class LRUCache {
public:
    int capacity_;
    std::list<std::pair<int, int>> kv_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map_;

    LRUCache(int capacity) : capacity_(capacity) {

    }
    
    int get(int key) {
        auto iter = map_.find(key);
        if (iter == map_.end()) {
            return -1;
        }

        kv_.emplace_back(key, iter->second->second);
        kv_.erase(iter->second);
        map_[key] = std::prev(kv_.end());
        return map_[key]->second;
    }
    
    void put(int key, int value) {
        if (map_.find(key) == map_.end()) {
            kv_.emplace_back(key, value);
            map_[key] = std::prev(kv_.end());
            if (kv_.size() > capacity_) {
                auto pair = kv_.begin();
                map_.erase(pair->first);
                kv_.pop_front();
            }
        }
        else {
            auto iter = map_[key];
            kv_.erase(iter);
            kv_.emplace_back(key, value);
            map_[key] = std::prev(kv_.end());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */