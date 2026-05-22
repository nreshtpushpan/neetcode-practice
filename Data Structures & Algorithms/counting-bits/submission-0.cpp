class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> results(n+1);
        for(int i = 0; i <= n; i++) {
            int num = i;
            int ans = 0;
            while(num) {
                ans += num&1;
                num >>= 1;
            }
            results[i] = ans;
        }
        return results;
    }
};
