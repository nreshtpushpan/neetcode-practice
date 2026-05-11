class Solution {
public:

    vector<int> partitionLabels(string s) {
        unordered_map<int, int> mp;
        int n = (int)s.size();
        for(int i = 0; i < n; i++) mp[s[i]] = i;
        vector<int> res;
        int size = 0, end = 0;
        for(int i = 0; i < n; i++) {
            ++size;
            end = max(end, mp[s[i]]);
            if(end == i) {
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};
