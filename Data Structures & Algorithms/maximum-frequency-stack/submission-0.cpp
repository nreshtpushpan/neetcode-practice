class FreqStack {
public:
    map<int, vector<long long>> buck;
    unordered_map<long long, int> mp;
    FreqStack() {
        buck.empty();
        mp.empty();
    }
    
    void push(int val) {
        buck[++mp[val]].push_back(val);
    }
    
    int pop() {
        auto it = buck.rbegin();
        long long val = it->second.back();
        mp[val]--;
        it->second.pop_back();
        if(it->second.empty()) buck.erase(--buck.end());
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */