class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = (int)tasks.size();
        if(n == 0) return {};
        for(int i = 0; i < n; i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        int curTime = tasks[0][0], i = 1;
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({tasks[0][1], tasks[0][2]});
        while(!pq.empty()) {
            auto taskD = pq.top();
            pq.pop();
            int processTime = taskD.first;
            int taskId = taskD.second;
            res.push_back(taskId);
            curTime += processTime;
            while(i < n && curTime >= tasks[i][0]) {
                pq.push({tasks[i][1], tasks[i][2]});
                ++i;
            }
            if(pq.empty() && i < n) {
                curTime = tasks[i][0];
                pq.push({tasks[i][1], tasks[i][2]});
                ++i;
            }
        }
        return res;
    }
};