class Solution {
public:
    void pushInterval(vector<vector<int>> &final, const vector<int> &interval) {
        if(final.empty() || final.back()[1] < interval[0]) {
            final.push_back(interval);
            return;
        }
        final.back()[1] = max(final.back()[1], interval[1]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> finalIntervals;
        for(auto interval : intervals) {
            pushInterval(finalIntervals, interval);
        }
        return finalIntervals;
    }
};
