class Solution {
public:
    vector<vector<int>> results;
    void recur(const vector<int> &nums, const int &n, vector<int> &cur, int hash) {
        if((int)cur.size() == n) {
            results.push_back(cur);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(hash & (1 << i)) continue;
            cur.push_back(nums[i]);
            recur(nums, n, cur, hash | (1 << i));
            cur.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> cur;
        recur(nums, n, cur, 0);
        return results;
    }
};
