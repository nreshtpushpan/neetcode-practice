class Solution {
public:
    vector<vector<int>> result;
    void recur(const vector<int>& nums, const int &n, vector<int> cur, int bitMap) {
        if((int)cur.size() == n) {
            result.push_back(cur);
            return;
        }
        int prev = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(bitMap & (1 << i)) continue;
            if(prev == nums[i]) continue;
            prev = nums[i];
            cur.push_back(nums[i]);
            recur(nums, n, cur, bitMap | (1 << i));
            cur.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> cur;
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        recur(nums, n, cur, 0);
        return result;
    }
};