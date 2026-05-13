class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        int t0 = 0, t1 = 1, t2 = 1;
        for(int i = 3; i <= n; i++) {
            int sum = t2 + t1 + t0;
            t0 = t1;
            t1 = t2;
            t2 = sum;
        }
        return t2;
    }
};