class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return x;
        if(x <= 3) return 1;
        long long l = 1, r = x;
        while(l < r) {
            long long m = (r - l + 1)/2 + l;
            if(m * m <= x) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return r;
    }
};