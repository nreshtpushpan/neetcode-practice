class Solution {
public:
    int countDaysWithCapacity(const vector<int>& weights, const int &capacity) {
        int days = 0;
        int sum = 0;
        for(auto w : weights) {
            if(sum + w > capacity) {
                ++days;
                sum = w;
            } else {
                sum += w;
            }
        }
        if(sum) ++days;
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = (int)weights.size();
        int totalWeight = 0, maxPackage = 0;
        for(auto w : weights) {
            totalWeight += w;
            maxPackage = max(maxPackage, w);
        }
        if(days == 1) return totalWeight;
        int l = maxPackage, r = totalWeight;
        int minW = totalWeight;
        while(l <= r) {
            int m = (r-l)/2 + l;
            int daysReq = countDaysWithCapacity(weights, m);
            if(daysReq <= days) {
                minW = min(minW, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return minW;
    }
};