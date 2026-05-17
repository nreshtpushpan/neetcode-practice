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
        for(int i = 0; i < n; i++) {
            if(!isAdded && newInterval[0] <= intervals[i][0]) {
                merge(mergedInterval, newInterval);
                isAdded = true;
            }
            merge(mergedInterval, intervals[i]);
        }
        if(!isAdded) merge(mergedInterval, newInterval);

        return mergedInterval;
    }
};
