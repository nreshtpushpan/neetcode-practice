class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty()) return true;
        int n = (int)nums.size();
        unordered_set<int> hash;
        int l = 0;
        for(int r = 0; r < n; r++) {
            if(r - l > k) {
                hash.erase(hash.find(nums[l]));
                ++l;
            }
            auto it = hash.insert(nums[r]);
            if(!it.second) return true;
        }
        return false;
    }
};