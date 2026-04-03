class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = (int)queries.size();
        vector<pair<int,int>> q(n);
        for(int i = 0; i < n; i++) q[i] = {queries[i], i};
        sort(q.begin(), q.end());
        sort(intervals.begin(), intervals.end());
        vector<int> ans(n);
        int m = (int)intervals.size();
        int j = 0;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n; i++) {
            int index = q[i].second;
            int val = q[i].first;
            while(j < m && val >= intervals[j][0]) {
                pq.push({-(intervals[j][1] - intervals[j][0] + 1), intervals[j][1]});
                ++j;
            }
            while(!pq.empty() && pq.top().second < val) pq.pop();
            ans[index] = pq.empty() ? -1 : -pq.top().first;
        }
        return ans;
    }
};
