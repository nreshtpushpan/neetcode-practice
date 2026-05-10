class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = (int)tasks.size();
        if(n == 0) return {};
        for(int i = 0; i < n; i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        
        auto comp = [&](int a, int b) {
            return tasks[a][1] > tasks[b][1] ||
                   (tasks[a][1] == tasks[b][1] && tasks[a][2] > tasks[b][2]);
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        int curTime = tasks[0][0], i = 0;
        vector<int> res;
        while(!pq.empty() || i < n ) {
            while(i < n && tasks[i][0] <= curTime) {
                pq.push(i);
                ++i;
            }
            if(pq.empty()) {
                curTime = tasks[i][0];
            } else {
                auto taskId = pq.top();
                pq.pop();
                res.push_back(tasks[taskId][2]);
                curTime += tasks[taskId][1];
            }
        }
        return res;
    }
};