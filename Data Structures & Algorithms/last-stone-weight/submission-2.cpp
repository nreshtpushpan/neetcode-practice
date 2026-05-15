class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = (int)stones.size();
        for(int i = 0; i < n; i++) pq.push(stones[i]);
        while(pq.size() >= 2) {
            auto x = pq.top();
            pq.pop();
            auto y  = pq.top();
            pq.pop();
            if(x == y) continue;
            pq.push(x-y);
        }
        return (!pq.empty()) ? pq.top() : 0;
    }
};
