class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = (int)intervals.size();
        int removed = 0;
        int lastEnd = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] >= lastEnd) {
                lastEnd = intervals[i][1];
                continue;
            }
            ++removed;
            lastEnd = min(lastEnd, intervals[i][1]);
        }
        return removed;
    }
};
