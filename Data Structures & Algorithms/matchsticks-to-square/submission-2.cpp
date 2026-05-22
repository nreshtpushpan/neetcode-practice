class Solution {
public:
    bool recur(const vector<int> &nums, const int &n, const int &target, int k, int curSum, int start, int hash) {
        if(k == 0) return true;
        if(curSum == target) return recur(nums, n, target, k-1, 0, 0, hash);
        for(int i = start; i < n; i++) {
            if(nums[i] + curSum > target) continue;
            if(hash & (1 << i)) continue;
            if(recur(nums, n, target, k, nums[i] + curSum, i+1, hash | (1 << i))) return true;
            if(curSum == 0) return false;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(total%4) return false;
        int n = (int)matchsticks.size();
        sort(matchsticks.rbegin(), matchsticks.rend());
        return recur(matchsticks, n, total/4, 4, 0, 0, 0);
    }
};