class Solution {
public:
    int sumDigit(int num) {
        int sum = 0;
        while(num) {
            int dig = num%10;
            sum += dig*dig;
            num /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = sumDigit(n);
        while(slow != fast) {
            fast = sumDigit(sumDigit(fast));
            slow = sumDigit(slow);
        }
        return fast == 1;
    }
};
