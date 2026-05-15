class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> peopleCount(1001, 0);
        for(auto trip : trips) {
            peopleCount[trip[1]] += trip[0];
            peopleCount[trip[2]] -= trip[0];
        }
        for(int i = 1; i <= 1000; i++) {
            peopleCount[i] += peopleCount[i-1];
            if(peopleCount[i] > capacity) return false;
        }
        return true;
        
    }
};