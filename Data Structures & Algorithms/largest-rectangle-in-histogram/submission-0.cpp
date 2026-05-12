class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = (int)h.size();
        stack<pair<int, int>> st;
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int left = i;
            while(!st.empty() && st.top().second > h[i]) {
                auto [index, height] = st.top();
                st.pop();
                maxArea = max(maxArea, (height * (i - index)));
                left = index;
            }
            st.push({left, h[i]});
        }
        while(!st.empty()) {
            auto [index, height] = st.top();
            st.pop();
            maxArea = max(maxArea, (height * (n - index)));
        }
        return maxArea;
    }
};
