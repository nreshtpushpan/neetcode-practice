class Solution {
public:
    int trap(vector<int>& h) {
        int n = (int)h.size();
        if(n == 0) return n;
        stack<int> st;
        int area = 0;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && h[i] > h[st.top()]) {
                int curH = h[st.top()];
                st.pop();
                if (st.empty()) break;
                int leftIndex = st.top();
                int leftM = h[leftIndex];
                int rightM = h[i];
                area += (i - leftIndex - 1) * (min(leftM, rightM) - curH);
            }
            st.push(i);
        }
        return area;
    }
};