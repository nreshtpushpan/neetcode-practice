class Solution {
public:
    int N;
    vector<vector<int>> dp;
    int recur(const vector<int>& prices, int curDay, int lastBuy) {
        if(curDay >= N) return 0;
        bool isSold = (lastBuy == -1);
        if(dp[curDay][isSold] != -1) return dp[curDay][isSold];
        int profit = 0;
        for(int i = curDay; i < N; i++) {
            if(lastBuy == -1) {
                profit = max(profit, recur(prices, i+1, i));
            } else {
                profit = max(profit, max(0, prices[i] - prices[lastBuy]) + recur(prices, i+2, -1));
            }
        }
        return dp[curDay][isSold] = profit;
    }
    int maxProfit(vector<int>& prices) {
        N = (int)prices.size();
        dp.resize(N, vector<int> (2, -1));
        return recur(prices, 0, -1);
    }
};
