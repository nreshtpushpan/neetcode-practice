class Solution {
public:
    int target;

    bool recur(const vector<int> &nums, const int n, int curSum, int hash, int k, int index) {
        if(curSum == target) {
            return recur(nums, n, 0, hash, k-1, 0);
        }
        if(k == 0) return true;
        for(int i = index; i < n; i++) {
            if(hash & (1 << i)) continue;
            if(curSum + nums[i] > target) continue;
            if(recur(nums, n, curSum + nums[i], hash | (1 << i), k, i+1)) return true;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k == 1) return true;
        int n = (int)nums.size();
        int sum = 0;
        for(auto num: nums) sum += num;
        if(sum%k) return false;
        sort(nums.begin(), nums.end());
        target = sum/k;
        return recur(nums, n, 0, 0, k, 0);
    }
};