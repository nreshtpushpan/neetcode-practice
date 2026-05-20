class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        int n = (int)nums.size();
        for(int i = 0; i < n; i++) {
            switch(nums[i]) {
                case 0 : {
                    ++red;
                    break;
                }
                case 1: {
                    ++white;
                    break;
                }
                default: {
                    ++blue;
                }
            }
        }
        int i = 0;
        while(red--) nums[i++] = 0;
        while(white--) nums[i++] = 1;
        while(blue--) nums[i++] = 2; 
    }
};