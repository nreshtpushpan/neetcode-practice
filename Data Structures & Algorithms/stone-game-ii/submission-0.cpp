class Solution {
public:
    map<tuple<int,int,bool>, int> dp;
    int recur(const vector<int>& piles, int n, bool isAlice, int l, int m) {
        if(l >= n) return 0;
        auto it = dp.find({l, m, isAlice});
        if(it != dp.end()) return it->second;
        int curMax = 0;
        int aliceMax = isAlice ? 0 : INT_MAX;
        for(int i = 1; i <= m; i++) {
            if(i + l - 1 >= n) break;
            if(isAlice) {
                curMax += piles[l+i-1];
                aliceMax = max(aliceMax, curMax + recur(piles, n, !isAlice, l+i, max(m, i*2)));
            } else {
                aliceMax = min(aliceMax, recur(piles, n, !isAlice, l+i, max(m, i*2)));
            }
        }
        
        return dp[{l, m, isAlice}] = aliceMax;
    }
    int stoneGameII(vector<int>& piles) {
        int n = (int)piles.size();
        return recur(piles, n, true, 0, 2);
    }
};