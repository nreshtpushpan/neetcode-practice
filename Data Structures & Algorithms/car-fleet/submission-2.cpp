class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = (int)position.size();
        vector<pair<int,int>> grid(n);
        for(int i = 0; i < n; i++) {
            grid[i] = {position[i], speed[i]};
        }
        sort(grid.begin(), grid.end(), [&](const pair<int,int> &a, const pair<int,int> &b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        });
        float lastArrivalTime = -1;
        int totalFeets = 0;
        for(int i = 0; i < n; i++) {
            int pos = grid[i].first;
            int speed = grid[i].second;
            float timeReq = (float)(target - pos)/(float)speed;
            if(lastArrivalTime < timeReq) {
                lastArrivalTime = timeReq;
                ++totalFeets;            
            }
        }
        return totalFeets;
    }
};
