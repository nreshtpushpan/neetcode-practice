class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       // sort(arr.begin(), arr.end());
        priority_queue<pair<int,int>> pq;
        for(auto num : arr) {
            pq.push({abs(x - num), num});
            if(pq.size() > k) pq.pop();
        }
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
};