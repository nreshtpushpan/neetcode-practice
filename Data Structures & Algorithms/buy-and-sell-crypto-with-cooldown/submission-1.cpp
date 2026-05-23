class Solution {
public:
    int N;
    vector<vector<int>> dp;
    int recur(const vector<int>& prices, int curDay, bool buy) {
        if(curDay >= N) return 0;
        if(dp[curDay][buy] != -1) return dp[curDay][buy];
        int buying = 0, selling = 0;
        if(buy) buying = recur(prices, curDay + 1, !buy) - prices[curDay];
        else selling = recur(prices, curDay + 2, !buy) + prices[curDay];
        int coolDown = recur(prices, curDay + 1, buy);
        return dp[curDay][buy] = max({buying, selling, coolDown});
    }
    int maxProfit(vector<int>& prices) {
        N = (int)prices.size();
        dp.resize(N, vector<int> (2, -1));
        return recur(prices, 0, true);
    }
};
