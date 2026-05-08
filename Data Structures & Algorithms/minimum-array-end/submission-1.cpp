class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        long long m = n - 1;
        long long xl = x;   // ✅ avoid UB for i >= 32
        int j = 0;
        for(int i = 0; (m >> j) > 0; i++) {
            if(!((xl >> i) & 1)) {
                if((m >> j) & 1)
                    result |= (1LL << i);
                j++;
            }
        }
        return result;
    }
};