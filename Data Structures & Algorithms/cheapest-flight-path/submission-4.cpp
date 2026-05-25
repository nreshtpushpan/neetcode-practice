class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        for(int i = 0; i <= k; i++) {
            vector<int> temp = prices;
            for(auto f : flights) {
                auto from = f[0];
                auto to = f[1];
                auto price = f[2];
                if(prices[from] == INT_MAX) continue;
                temp[to] = min(temp[to], prices[from] + price);
            }
            prices = temp;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
