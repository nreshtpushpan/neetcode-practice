class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size();
        int index = 0;
        int curSum = 0, totalSum = 0;
        for(int i = 0; i < n; i++) {
            int diff = (gas[i] - cost[i]);
            curSum += diff;
            totalSum += diff;
            if(curSum < 0) {
                curSum = 0;
                index = i+1;
            }
        }
        return totalSum >= 0 ? index : -1;
    }
};
