class Solution {
public:
    double expBase(double base, int exp) {
        double ans = 1.0;
        while(exp) {
            if(exp&1) {
                ans *= base;
            }
            base *= base;
            exp /= 2;
        }
        return ans;
    }
    double myPow(double x, int n) {
        if(x == 0) return x;
        if(n == 0) return 1;
        double ans = expBase(abs(x), abs(n));
        if(n < 0) ans = 1.0/ans;
        if(x < 0 && abs(n)&1) ans = -ans;
        return ans;
    }
};
