class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = (int)prices.size();
        int maxP = 0, maxS = 0;
        for(int i = n-1; i >= 0; i--) {
            maxS = max(maxS, prices[i]);
            maxP = max(maxP, maxS - prices[i]);
        }
        return maxP;
    }
};
