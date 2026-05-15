class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int n = (int)digits.size();
        int carry = 1;
        for(int i = 0; i < n; i++) {
            int sum = digits[i] + carry;
            digits[i] = sum%10;
            carry = sum/10;
        }
        if(carry) digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
