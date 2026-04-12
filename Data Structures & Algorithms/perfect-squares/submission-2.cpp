class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n);
        dp[0] = 0;
        for(int j = 1; j * j <= n; j++) {
            //cout<< num<<endl;
            int num = j*j;
            for(int i = num; i <= n; i++) {
                dp[i] = min(dp[i], dp[i - num] + 1);
                //cout<<i<<" "<<dp[i]<<" ";
            }
            //cout<<endl;
        }

        return dp[n];
    }
};