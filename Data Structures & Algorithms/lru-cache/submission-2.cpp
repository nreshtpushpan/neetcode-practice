class LRUCache {
public:
    int maxSize;
    list<int> dq;
    unordered_map<int, list<int>::iterator> freq;
    unordered_map<int, int> cache;
    LRUCache(int capacity) {
        maxSize = capacity;
    }
    
    void updateFreq(int key) {
        auto node = freq.find(key);
        if(node != freq.end()) deleteKey(key);    
        dq.push_back(key);
        freq[key] = prev(dq.end());
    }

    void deleteKey(int key) {
        auto node = freq.find(key);
        if(node != freq.end()) {
            dq.erase(node->second);
            freq.erase(node);
        }
    }

    void deleteCacheKey() {
        int key = dq.front();
        deleteKey(key);
        cache.erase(key);
    }

    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end()) return -1;
        updateFreq(key);
        return it->second;
    }
    
    void put(int key, int value) {
        int siz = cache.size();
        auto it = cache.find(key);
        if(siz == maxSize && it == cache.end()) deleteCacheKey();
        cache[key] = value;
        updateFreq(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */