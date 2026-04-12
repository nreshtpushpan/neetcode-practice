class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        for(int i = 1; i <= 100; i++) {
            int square = i*i;
            if(square > n) break;
            sq.push_back(square);
        }
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(auto num : sq) {
            //cout<< num<<endl;
            for(int i = num; i <= n; i++) {
                dp[i] = min(dp[i], dp[i - num] + 1);
                //cout<<i<<" "<<dp[i]<<" ";
            }
            //cout<<endl;
        }
        return dp[n];
    }
};