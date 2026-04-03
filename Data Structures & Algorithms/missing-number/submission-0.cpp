class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XOR = 0;
        for(auto num: nums) XOR ^= num;
        for(int i = 0; i <= (int)nums.size(); i++) XOR ^= i;
        return XOR;
    }
};
