class StockSpanner {
public:
    vector<int> tail;
    vector<int> dp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(tail.empty() || tail.back() > price ) {
            tail.push_back(price);
            dp.push_back(1);
            return 1;
        }
        int res = 1;
        int lastIndex = tail.size() - 1;
        while(lastIndex >= 0 && tail[lastIndex] <= price) {
            res += dp[lastIndex];
            lastIndex -= dp[lastIndex];
        }
        tail.push_back(price);
        dp.push_back(res);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */