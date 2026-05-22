class Solution {
public:
    int N;
    bitset<100001> hash;
    map<pair<long long, long long>, long> dp;
    long long recur(const vector<pair<long long, long long>> &project, long long remProject, long long curCapital) {
        if(remProject == 0) return curCapital;
        pair<long long, long long> p = {remProject, curCapital};
        if(dp.count(p)) return dp[p];
        long long curProfit = curCapital;
        for(int i = 0; i < N; i++) {
            if(hash.test(i)) continue;
            if(project[i].first > curCapital) continue;
            hash.set(i);
            curProfit = max(curProfit, recur(project, remProject - 1, curCapital + project[i].second));
            hash.reset(i);
        }
        return dp[p] = curProfit;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        N = (int)profits.size();
        vector<pair<long long, long long>> project(N);
        for(int i = 0; i < N; i++) project[i] = {capital[i], profits[i]};
        return recur(project, k, w);
    }
};