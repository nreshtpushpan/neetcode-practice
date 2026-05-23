class MyHashSet {
public:
    bitset<1000001> hash;
    MyHashSet() {
    }
    
    void add(int key) {
        hash.set(key);
    }
    
    void remove(int key) {
        hash.reset(key);
    }
    
    bool contains(int key) {
        return hash.test(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */