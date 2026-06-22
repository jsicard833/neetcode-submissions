class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        auto it = key_index.find(key);
        if (it != key_index.end()) {
            auto [key, value] = *(it->second);
            lru.erase(it->second);
            lru.emplace_back(key, value);
            key_index[key] = (--lru.end());
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = key_index.find(key);
        if (it != key_index.end()) {
            lru.erase(it->second);
        }
        lru.emplace_back(key, value);
        key_index[key] = (--lru.end());
        if (lru.size() > capacity) {
            int oldestKey = lru.front().first;
            key_index.erase(oldestKey);
            lru.pop_front();
        }
    }
private:
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> key_index;
    int capacity;
};
