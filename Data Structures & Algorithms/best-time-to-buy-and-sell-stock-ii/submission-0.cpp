class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        int maxVal = INT_MIN;
        int profit = 0;
        for(int i = n-1; i >= 0; i--) {
            if(prices[i] < maxVal) {
                profit += maxVal - prices[i];
                maxVal = prices[i];
            } else {
                maxVal = max(maxVal, prices[i]);
            }
        }
        return profit;
    }
};