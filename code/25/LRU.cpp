#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public: 
    LRUCache(int capacity): size(capacity) {
    }

    int get(int key) {
        if (u_map.count(key) == 0) return -1;
        auto key_ = u_map[key];
        return key_->second;
    }
    
    void put(int key, int value) {
        if (u_map.count(key) == 0) {
            list_.push_front({key, value});
            u_map[key] = list_.begin(); 
        } else {
            list_.erase(u_map[key]);
            u_map.erase(key);
            list_.push_front({key, value});
            u_map[key] = list_.begin();
        }
        while (list_.size() > size) {
            auto it = u_map[list_.back().first];
            u_map.erase(list_.back().first);
            list_.erase(it);
        }
    }
private:
    list<pair<int, int>> list_;
    unordered_map<int, list<pair<int, int>>::iterator> u_map;
    int size;
};
int main() {
    auto cache = new LRUCache(4);
    cache->put(1, 1);
    cache->put(2, 1);
    cache->put(3, 1);
    cache->put(4, 1);
    cache->put(5, 1);
    cout << cache->get(1);
    cout << cache->get(3);
}



