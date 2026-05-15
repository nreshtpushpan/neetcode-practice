class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = (int)ratings.size();
        vector<int> dp(n, -1);
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<>> pq;
        for(int i = 0; i < n; i++) pq.push({ratings[i], i});
        int totalCandies = 0;
        while(!pq.empty()) {
            auto [rate, index] = pq.top();
            pq.pop();
            int leftIndex = (index-1) < 0 ? index : index - 1;
            int rightIndex = (index+1) == n ? index : index + 1;
            if(ratings[leftIndex] < rate && ratings[rightIndex] < rate) {
                totalCandies += max(dp[leftIndex], dp[rightIndex]) + 1;
                dp[index] = max(dp[leftIndex], dp[rightIndex]) + 1;
            } else if(ratings[leftIndex] >= rate && ratings[rightIndex] >= rate) {
                totalCandies += 1;
                dp[index] = 1;
            } else if(leftIndex == index) {
                if(ratings[rightIndex] < rate) {
                    totalCandies += dp[rightIndex] + 1;
                    dp[index] = dp[rightIndex] + 1;
                } else {
                    totalCandies += 1;
                    dp[index] = 1;
                }
            }  else if(rightIndex == index) {
                if(ratings[leftIndex] < rate) {
                    totalCandies += dp[leftIndex] + 1;
                    dp[index] = dp[leftIndex] + 1;
                } else {
                    totalCandies += 1;
                    dp[index] = 1;
                }
            } else {
                if(ratings[leftIndex] < rate && ratings[rightIndex] >= rate) {
                    totalCandies += dp[leftIndex] + 1;
                    dp[index] = dp[leftIndex] + 1;
                } else if(ratings[leftIndex] >= rate && ratings[rightIndex] < rate) {
                    totalCandies += dp[rightIndex] + 1;
                    dp[index] = dp[rightIndex] + 1;
                }
            }
        }
        return totalCandies;
    }
};