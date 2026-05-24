class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = (int)arr.size();
        if(n == 1) return n;
        bool isGreater = true;
        int count = 0, maxL = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i-1]) {
                count = (isGreater) ? count + 1 : 1;
                isGreater = false;
            } else if (arr[i] < arr[i-1]) {
                count = (!isGreater) ? count + 1 : 1;
                isGreater = true;
            } else {
                count = 0;
                isGreater = false;
            }
            maxL = max(maxL, count);
        }
        return maxL+1;
    }
};