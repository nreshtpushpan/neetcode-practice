class Solution {
public:
    int trap(vector<int>& h) {
        int r = (int)h.size() - 1;
        int l = 0;
        int maxL = h[l], maxR = h[r];
        int area = 0;
        while(l < r) {
            if(maxL < maxR) {
                ++l;
                maxL = max(maxL, h[l]);
                area += maxL - h[l];
            } else {
                --r;
                maxR = max(maxR, h[r]);
                area += maxR - h[r];
            }
        }
        return area;
    }
};