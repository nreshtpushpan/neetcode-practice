class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        set<pair<long long,int>> busy;
        set<int> free;
        for(int i = 0; i < n; i++) free.insert(i);
        vector<int> count(n, 0);
        sort(meetings.begin(), meetings.end());
        for(auto m: meetings) {
            long long start = m[0];
            long long dur = m[1] - m[0];
            while(!busy.empty() && (*busy.begin()).first <= start) {
                auto it = busy.begin();
                free.insert((*it).second);
                busy.erase(it);
            }
            if(!free.empty()) {
                auto it = free.begin();
                count[*it]++;
                busy.insert({start + dur, *it});
                free.erase(it);
            } else {
                auto it = busy.begin();
                int roomNo = (*it).second;
                long long endTime = (*it).first;
                busy.erase(it);
                busy.insert({endTime + dur, roomNo});
                count[roomNo]++;
            }
        }
        return max_element(count.begin(), count.end()) - count.begin();
    }
};
