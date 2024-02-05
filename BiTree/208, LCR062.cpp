#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

class Trie {
public:
    std::vector<Trie*> next;
    bool isEnd;
    /** Initialize your data structure here. */
    Trie() : next(26), isEnd(false) {

    }
    
    /** Inserts a word into the trie. */
    void insert(std::string word) {
        Trie* cur = this;
        
        for (auto c : word) {
            if (!cur->next[c - 'a'])
                cur->next[c - 'a'] = new Trie();
            cur = cur->next[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        Trie* cur = this;

        for (auto c : word) {
            if (cur->next[c - 'a'])
                cur = cur->next[c - 'a'];
            else return false;
        }
        if (cur->isEnd) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        Trie* cur = this;

        for (auto c : prefix) {
            if (cur->next[c - 'a'])
                cur = cur->next[c - 'a'];
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */