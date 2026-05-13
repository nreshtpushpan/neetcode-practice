class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = (int)arr.size();
        auto index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = index - 1, r = index;
        while(k--) {
            if(l < 0) ++r;
            else if (r == n) --l;
            else if(abs(arr[l] - x) <= abs(arr[r] - x)) --l;
            else ++r;
        }
        vector<int> result(arr.begin() + l + 1, arr.begin() + r);  
        return result;  
    }
};