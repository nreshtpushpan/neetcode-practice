class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(auto a: asteroids) {
            while(!st.empty() && a < 0 && st.back() > 0) {
                int diff = a + st.back();
                if(diff < 0) {
                    st.pop_back();
                } else if(diff > 0) {
                    a = 0;
                } else {
                    a = 0;
                    st.pop_back();
                }
            }
            if(a != 0) st.push_back(a);
        }
        return st;
    }
};