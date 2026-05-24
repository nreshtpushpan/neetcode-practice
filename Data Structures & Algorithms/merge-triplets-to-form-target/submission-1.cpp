class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> result(3, 0);
        for(auto trip : triplets) {
            if(max(result[0], trip[0]) > target[0] || max(result[1], trip[1]) > target[1] || max(result[2], trip[2]) > target[2]) {
                continue;
            }
            result[0] = max(result[0], trip[0]);
            result[1] = max(result[1], trip[1]);
            result[2] = max(result[2], trip[2]);
        }
        return result == target;
    }
};
