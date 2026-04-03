class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.empty()) return false;
        unordered_set<int> hash;
        for(auto num: nums) {
            auto it = hash.find(num);
            if(it != hash.end()) return true;
            hash.insert(num);
        }
        return false;
        
    }
};