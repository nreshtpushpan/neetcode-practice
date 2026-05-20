class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = (int)nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            auto y = mp.find(target - nums[i]);
            if(y != mp.end()) return {y->second , i};
            mp[nums[i]] = i;
        }
        return {};
    }
};
