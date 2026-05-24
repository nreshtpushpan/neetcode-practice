class Solution {
public:
    int N;
    vector<vector<int>> results;
    void recur(const vector<int> &nums, vector<int> &cur, int index) {
        results.push_back(cur);  // add at every level
        for(int i = index; i < N; i++) {
            if(i > index && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            recur(nums, cur, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        N = (int)nums.size();
        vector<int> cur;
        sort(nums.begin(), nums.end());
        recur(nums, cur, 0);
        return results;
    }
};
