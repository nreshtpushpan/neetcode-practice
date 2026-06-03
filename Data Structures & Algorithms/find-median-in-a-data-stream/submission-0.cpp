class MedianFinder {
public:
    priority_queue<int> lMax;
    priority_queue<int, vector<int>, greater<>> rMin;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int n = lMax.size();
        int m = rMin.size();
        if(n == 0) {
            lMax.push(num);
            return;
        }
        if(m < n) {
            if(num >= lMax.top()) {
                rMin.push(num);
            }else {
                rMin.push(lMax.top());
                lMax.pop();
                lMax.push(num);
            }
            return;
        }
        int l = lMax.top();
        lMax.pop();
        int r = rMin.top();
        rMin.pop();
        lMax.push(min(l, r));
        rMin.push(max(l, r));
        if(num >= rMin.top()) {
            lMax.push(rMin.top());
            rMin.pop();
            rMin.push(num);
        } else lMax.push(num);
    }
    
    double findMedian() {
        int n = lMax.size();
        int m = rMin.size();
        if((n+m)&1) return (double)lMax.top();
        double sum = (double)lMax.top() + (double)rMin.top();
        return sum/2;
    }
};
