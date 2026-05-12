class Solution {
public:
    int add(int a, int b) {
        int res = 0;
        int carry = 0;
        for(int i = 0; i < 32; i++) {
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            int digit = bitA ^ bitB ^ carry;
            carry = (bitA && bitB) || (bitA && carry) || (bitB && carry);
            res |= (digit << i);
        }
        return res;
    }
    int getSum(int a, int b) {
  
       return add(a, b);
    }
};
