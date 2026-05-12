class Solution {
public:
    int add(int a, int b) {
        int res = 0;
        int carry = 0;
        for(int i = 0; i < 32; i++) {
            int digit = (a&1) ^ (b&1) ^ carry;
            carry = ((a&1) && (b&1)) ||  ((a&1) && (carry&1)) || ((carry&1) && (b&1));
            res |= (digit << i);
            a >>= 1;
            b >>= 1;
        }
        return res;
    }
    int getSum(int a, int b) {
      // if(a < 0) a = add(~a, 1);
      // if(b < 0) b = add(~b, 1);
       return add(a, b);
    }
};
