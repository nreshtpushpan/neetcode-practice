class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0, r = (int)h.size() - 1;
        int area = 0;
        while(l < r) {
            area = max(area, (r-l) * min(h[l], h[r]));
            if(h[l] < h[r])++l;
            else --r;
        }
        return area;
    }
};
