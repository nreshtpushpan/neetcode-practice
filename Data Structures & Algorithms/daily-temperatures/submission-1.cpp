class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = (int)temperatures.size();
        vector<int> result(n, 0);
        for(int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while(j < n && temperatures[j] <= temperatures[i]) {
                if(result[j] == 0) {
                    j = i;
                    break;
                }
                j += result[j];
            }
            result[i] = j - i;
        }
        return result;
    }
};
