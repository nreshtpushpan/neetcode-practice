class Solution {
public:
    int result = 0;
    void recur(const vector<int> &nums, const int &n, int index, int curXor) {
        result += curXor;
        for(int i = index; i < n; i++) {
            recur(nums, n, i + 1, curXor ^ nums[i]);
        }
    }
    int subsetXORSum(vector<int>& nums) {
        int n = (int)nums.size();
        recur(nums, n, 0, 0);
        return result;
    }
};