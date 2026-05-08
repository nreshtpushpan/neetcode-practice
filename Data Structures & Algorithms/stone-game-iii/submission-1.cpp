class Solution {
public:
    map<tuple<int,int,bool>, int> dp;
    int recur(const vector<int>& piles, int n, bool isAlice, int l, int m) {
        if(l >= n) return 0;
        auto it = dp.find({l, m, isAlice});
        if(it != dp.end()) return it->second;
        int curMax = 0;
        int aliceMax = isAlice ? INT_MIN : INT_MAX;
        for(int i = 1; i <= 3; i++) {
            if(i + l - 1 >= n) break;
            if(isAlice) {
                curMax += piles[l+i-1];
                aliceMax = max(aliceMax, curMax + recur(piles, n, !isAlice, l+i, i));
            } else {
                aliceMax = min(aliceMax, recur(piles, n, !isAlice, l+i, i));
            }
        }
        
        return dp[{l, m, isAlice}] = aliceMax;
    }

    string stoneGameIII(vector<int>& piles) {
        int n = (int)piles.size();
        int sum = accumulate(piles.begin(), piles.end(), 0);
        int aliceMax = max({recur(piles, n, true, 0, 1), recur(piles, n, true, 0, 2), recur(piles, n, true, 0, 3)});
        int bob = sum - aliceMax;  
        if(aliceMax > bob) return "Alice";
        if(aliceMax == bob) return "Tie";
        return "Bob";
    }
};