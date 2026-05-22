class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = (int)profits.size();
        vector<pair<long long, long long>> project(n);
        for(int i = 0; i < n; i++) project[i] = {capital[i], profits[i]};
        sort(project.begin(), project.end());
        priority_queue<long long> pq;
        int i = 0;
        long long curCapital = w;
        while(k--) {
            while(i < n && curCapital >= project[i].first) {
                pq.push(project[i].second);
                ++i;
            }
            if(pq.empty()) return curCapital;
            curCapital += pq.top();
            pq.pop();
        }
        return curCapital;
    }
};