class Solution {
public:
    int reverse(int x) {
        int newX = 0;
        while(x) {
            int dig = x % 10;
            x /= 10;
            if(newX > (INT_MAX - dig) / 10) return 0;
            if(newX < (INT_MIN - dig) / 10) return 0;
            newX = newX * 10 + dig;
        }
        return newX;
    }
};
