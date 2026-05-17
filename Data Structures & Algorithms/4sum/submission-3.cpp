class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        vector<vector<int>> result;
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n; j++) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int l = j+1, r = n-1;
                while(l < r) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];
                    if(sum == (long long)target) {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l+1 < n && nums[l] == nums[l+1])++l;
                        while(r-1 >= 0 && nums[r] == nums[r-1])--r;
                        ++l;
                        --r;
                    } else if(sum < target)++l;
                    else --r;
                }
            }
        }
        return result;
    }
};