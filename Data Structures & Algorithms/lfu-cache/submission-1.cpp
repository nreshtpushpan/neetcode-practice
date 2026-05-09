class LFUCache {
public:
    int maxSize, minFreq;
    unordered_map<int, int> cache;
    unordered_map<int, int> freqCount;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> iterMap;

    LFUCache(int capacity) {
        maxSize = capacity;
        minFreq = 0;
    }

    void updateFreq(int key) {
        int f = freqCount[key];
        freqCount[key]++;
        freqList[f].erase(iterMap[key]);
        if(freqList[f].empty() && f == minFreq) minFreq++;
        freqList[f+1].push_back(key);
        iterMap[key] = prev(freqList[f+1].end());
    }

    void evict() {
        int key = freqList[minFreq].front();
        freqList[minFreq].pop_front();
        iterMap.erase(key);
        freqCount.erase(key);
        cache.erase(key);
    }

    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        updateFreq(key);
        return cache[key];
    }

    void put(int key, int value) {
        if(maxSize == 0) return;
        if(cache.find(key) == cache.end()) {
            if((int)cache.size() == maxSize) evict();
            freqList[1].push_back(key);
            iterMap[key] = prev(freqList[1].end());
            freqCount[key] = 1;
            minFreq = 1;
        } else {
            updateFreq(key);
        }
        cache[key] = value;
    }
};