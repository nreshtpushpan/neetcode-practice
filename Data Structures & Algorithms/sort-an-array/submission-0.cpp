class Solution {
public:
    vector<int> merge(const vector<int> &a, const vector<int> &b) {
        int n = (int)a.size();
        int m = (int)b.size();
        vector<int> result(n+m);
        int i = 0, j = 0, k = 0;
        while(i < n && j < m) {
            if(a[i] <= b[j]) {
                result[k++] = a[i++];
            } else {
                result[k++] = b[j++];
            }
        }
        while(i < n) result[k++] = a[i++];
        while(j < m) result[k++] = b[j++];
        return result;
    }

    vector<int> mergeSort(const vector<int> &nums, int l, int e) {
        if(l >= e) return {nums[l]};
        int m = (e-l)/2 + l;
        auto a = mergeSort(nums, l, m);
        auto b = mergeSort(nums, m+1, e);
        return merge(a, b);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = (int)nums.size();
        return mergeSort(nums, 0, n-1);
    }
};