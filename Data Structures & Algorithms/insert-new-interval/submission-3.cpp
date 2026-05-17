class Solution {
public:
    void merge(vector<vector<int>> &mergedInterval, const vector<int> &newInterval) {
        if(mergedInterval.empty() || mergedInterval.back()[1] < newInterval[0]) {
            mergedInterval.push_back(newInterval);
            return;
        }
        mergedInterval.back()[1] = max(mergedInterval.back()[1], newInterval[1]);
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> mergedInterval;
        int n = (int)intervals.size();
        bool isAdded = false;
        int intervalsAdded = 0;
        for(int i = 0; i < n; i++) {
            if(!isAdded && newInterval[0] < intervals[i][0]) {
                merge(mergedInterval, newInterval);
                isAdded = true;
                intervalsAdded++;
            }
            if(!isAdded && newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1]) {
                merge(mergedInterval, intervals[i]);
                merge(mergedInterval, newInterval);
                isAdded = true;
                intervalsAdded += 2;
                continue;
            }
            merge(mergedInterval, intervals[i]);
            intervalsAdded++;
        }
        if(intervalsAdded != n + 1) merge(mergedInterval, newInterval);

        return mergedInterval;
    }
};
