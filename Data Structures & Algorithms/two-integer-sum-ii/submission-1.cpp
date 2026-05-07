class Solution {
public:
    int findNum(const vector<int> &num, int target) {
        int r = (int)num.size() - 1;
        int l = 0;
        int ans = -1;
        while(l <= r) {
            int m = (l + r)/2;
            if(num[m] == target) {
                ans = m;
                l = m + 1;
            } else if (num[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = (int) numbers.size();
        for(int i = 0; i+1 < n; i++) {
            if(numbers[i] != numbers[i+1]) {
                int index = findNum(numbers, target - numbers[i]);
                if(index != -1) return {min(i+1, index+1), max(i+1, index+1)};
            }
        }
        return {};
    }
};
