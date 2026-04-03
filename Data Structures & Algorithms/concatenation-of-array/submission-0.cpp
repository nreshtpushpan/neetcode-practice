class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        if(nums.empty()) return {};
        int n = (int)nums.size();
        vector<int> ans(2*n);
        for(int i = 0; i < n; i++) {
            ans[i] = ans[i+n] = nums[i];
        }
        return ans;
    }
};