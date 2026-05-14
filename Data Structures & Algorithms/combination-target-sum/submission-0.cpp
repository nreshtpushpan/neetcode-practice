class Solution {
public:
    set<vector<int>> result;
    void recur(const vector<int>& nums, vector<int> cur, int target) {
        if(target == 0) {
            sort(cur.begin(), cur.end());
            result.insert(cur);
            return;
        }
        for(auto num : nums) {
            if(target - num < 0) continue;
            cur.push_back(num);
            recur(nums, cur, target - num);
            cur.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        //sort(nums.begin(), nums.end());
        vector<int> cur;
        recur(nums, cur, target);
        vector<vector<int>> res;
        for(auto v: result) res.push_back(v);
        return res;
    }
};
