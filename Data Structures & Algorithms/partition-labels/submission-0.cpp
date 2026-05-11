class Solution {
public:
    void pushInterval(vector<pair<int, int>> &mergedIntervals, const pair<int, int> &interval) {
        if(mergedIntervals.empty() || mergedIntervals.back().second < interval.first) {
            mergedIntervals.push_back(interval);
            return;
        }
        mergedIntervals.back().second = max(mergedIntervals.back().second, interval.second);
    }
    vector<int> partitionLabels(string s) {
        unordered_map<int, pair<int,int>> mp;
        int n = (int)s.size();
        for(int i = 0; i < n; i++) {
            auto it = mp.find(s[i]);
            if(it == mp.end()) mp[s[i]] = {i, i};
            else it->second.second = i;
        }
        vector<pair<int,int>> intervals;
        for(auto it : mp) intervals.push_back({it.second.first, it.second.second});
        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>> mergedIntervals;
        for(auto interval : intervals) {
            pushInterval(mergedIntervals, interval);
        }
        vector<int> res;
        for(auto interval : mergedIntervals) res.push_back(interval.second - interval.first + 1);
        return res;
    }
};
