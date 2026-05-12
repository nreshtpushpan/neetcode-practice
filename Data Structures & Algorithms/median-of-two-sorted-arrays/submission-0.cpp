class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = (int)a.size();
        int m = (int)b.size();
        if(n > m) return findMedianSortedArrays(b, a);
        int l = 0, r = n;
        int total = n + m;
        int half = total/2;
        while(l <= r) {
            int i = (l + r)/2;
            int j = half - i;
            int Aleft  = (i > 0) ? a[i-1] : INT_MIN;   // i elements taken, leftmost is a[i-1]
            int Aright = (i < n) ? a[i]   : INT_MAX;
            int Bleft  = (j > 0) ? b[j-1] : INT_MIN;
            int Bright = (j < m) ? b[j]   : INT_MAX;
            if(Aleft <= Bright && Bleft <= Aright) {
                if(total & 1) return (double)min(Aright, Bright);
                else {
                    double left = max(Aleft, Bleft);
                    double right = min(Aright, Bright);
                    return (left + right)/2.0;
                }
            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return 0.0;
    }
};
