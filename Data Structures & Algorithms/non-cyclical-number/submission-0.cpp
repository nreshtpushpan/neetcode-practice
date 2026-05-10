class Solution {
public:
    unordered_set<int> mp;
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
        if(n == 1) return true;
        mp.insert(n);
        int sum = sumDigit(n);
        if(mp.find(sum) != mp.end()) return false;
        return isHappy(sum);
    }
};
