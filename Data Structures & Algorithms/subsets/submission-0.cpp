class Solution {
public:
    vector<vector<int>> results;
    void recur(const vector<int> &nums, vector<int> &cur, int index) {
        results.push_back(cur);
        for(int i = index; i < (int)nums.size(); i++) {
            if(i > index && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            recur(nums, cur, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        recur(nums, cur, 0);
        return results;
    }
};
