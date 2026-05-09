class Solution {
public:
    int climbStairs(int n) {
        if(n < 4) return n;
        int prev = 1, cur = 1;
        while(--n) {
            int newStep = prev + cur;
            prev = cur;
            cur = newStep;
        }
        return cur;
    }
};
