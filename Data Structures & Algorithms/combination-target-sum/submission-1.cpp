class Solution {
public:
    vector<vector<int>> result;
    void recur(const vector<int>& nums, vector<int> cur, int target, int index) {
        if(target == 0) {
            result.push_back(cur);
            return;
        }
        for(int i = index ; i < (int)nums.size(); i++) {
            int num = nums[i];
            if(target - num < 0) continue;
            cur.push_back(num);
            recur(nums, cur, target - num, i);
            cur.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        //sort(nums.begin(), nums.end());
        vector<int> cur;
        recur(nums, cur, target, 0);
        return result;
    }
};
