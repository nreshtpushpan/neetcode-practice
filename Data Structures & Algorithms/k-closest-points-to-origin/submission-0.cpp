class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = (int)points.size();
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n; i++) {
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if(pq.size() < k) {
                pq.push({dis, i});
            } else {
                if(pq.top().first > dis) {
                    pq.pop();
                    pq.push({dis, i});
                }
            }
        }
        vector<vector<int>> res(k);
        int i = 0;
        while(!pq.empty()) {
            res[i++] = points[pq.top().second];
            pq.pop();
        }
        return res;
    }
};
