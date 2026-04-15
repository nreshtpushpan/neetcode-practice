class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = (int)temperatures.size();
        vector<pair<int,int>> tail;
        vector<int> result(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            while(!tail.empty() && tail.back().first <= temperatures[i]) tail.pop_back();
            if(!tail.empty()) {
                result[i] = tail.back().second - i;
            }
            tail.push_back({temperatures[i], i});
        }
        return result;
    }
};
