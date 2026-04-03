class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty()) return true;
        int n = (int)nums.size();
        unordered_set<int> hash;
        for(int i = 0; i <= k && i < n; i++) hash.insert(nums[i]);
    
        if(hash.size() != min(k+1, n)) return true;
        for(int i = k+1; i < n; i++) {
            hash.erase(nums[i-k-1]);
            hash.insert(nums[i]);
            if(hash.size() != k+1) return true;
        }
        return false;
    }
};