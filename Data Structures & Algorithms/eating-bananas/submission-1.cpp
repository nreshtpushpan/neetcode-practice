class Solution {
public:
    int timeTakenWithSpeedK(const vector<int> &piles, int k) {
        int time = 0;
        for(auto pile : piles) {
            int timeTaken = pile/k + ((pile%k) ? 1 : 0);
            //cout<<pile<<" "<<k<<" "<<timeTaken<<endl;
            time += timeTaken;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = (int)piles.size();
        int r = *max_element(piles.begin(), piles.end());
        int l = 1;
        int ans = r;
        while(l <= r) {
            int k = (l + r)/2;
            int timeTaken = timeTakenWithSpeedK(piles, k);
            //cout<<k<<" - "<<timeTaken<<endl;
            if(timeTaken > h) {
                l = k+1;
            } else {
                ans = min(ans, k);
                r = k-1;
            }
        }
        return ans;
    }
};
