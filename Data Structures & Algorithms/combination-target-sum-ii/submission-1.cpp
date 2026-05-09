class Solution {
public:
    void recur(const vector<int> &nums, const int &n, int sum, int index, vector<int> &cur, vector<vector<int>> &res) {
        if(sum == 0) {
            res.push_back(cur);
            return;
        }
        if(index == n) return;
        for(int i = index; i < n; i++) {
            if(nums[i] > sum) break;
            if(i > index && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            recur(nums, n, sum-nums[i], i+1, cur, res);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        int n = (int)candidates.size();
        recur(candidates, n, target, 0, cur, res);
        return res;
    }
};
