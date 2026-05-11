class StockSpanner {
public:
    vector<pair<int,int>> tail;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!tail.empty() && tail.back().first <= price) {
            span += tail.back().second;
            tail.pop_back();
        }
        tail.push_back({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */