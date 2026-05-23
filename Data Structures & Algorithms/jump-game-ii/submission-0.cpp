class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int)nums.size();
        map<int, int> dp;
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            int j = i + nums[i];
            int curJump = dp.lower_bound(i)->second;
            if(dp.count(j)) dp[j] = min(dp[j], curJump + 1);
            else dp[j] = curJump + 1;
        }
        return dp.lower_bound(n-1)->second;
    }
};
