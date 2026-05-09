class TimeMap {
public:
    unordered_map<string, map<int,string>> mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        auto it = mp.find(key);
        if(it == mp.end()) {
            map<int,string> np;
            np[timestamp] = value;
            mp[key] = np;
            return;
        }
        it->second[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if(it == mp.end()) return "";
        auto innerIt = it->second.find(timestamp);
        if(innerIt != it->second.end()) {
            return innerIt->second;
        }
        auto lbInnerIt = it->second.lower_bound(timestamp);
        cout<<timestamp<<" "<<endl;
        if(lbInnerIt == it->second.begin()) return "";
        return (--lbInnerIt)->second;
    }
};
