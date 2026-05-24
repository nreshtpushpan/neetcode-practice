class MyHashMap {
public:
    int mod = 1e6 + 1;
    vector<int> hashMap;
    MyHashMap() {
        hashMap.resize(mod, -1);
    }
    
    void put(int key, int value) {
        hashMap[key] = value;
    }
    
    int get(int key) {
        int val =  hashMap[key];
        if(val != -1) return val;
    }
    
    void remove(int key) {
        hashMap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */