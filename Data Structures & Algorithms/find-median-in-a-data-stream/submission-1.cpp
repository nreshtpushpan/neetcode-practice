class MedianFinder {
public:
    priority_queue<int> lMax;
    priority_queue<int, vector<int>, greater<>> rMin;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lMax.push(num);
        if(!rMin.empty() && rMin.top() < lMax.top()) {
            rMin.push(lMax.top());
            lMax.pop();
        }
        int n = lMax.size();
        int m = rMin.size();
        if(n > m + 1) {
            rMin.push(lMax.top());
            lMax.pop();
        } else if(m > n) {
            lMax.push(rMin.top());
            rMin.pop();
        }
    }
    
    double findMedian() {
        int n = lMax.size();
        int m = rMin.size();
        if(n > m) return (double)lMax.top();
        double sum = (double)lMax.top() + (double)rMin.top();
        return sum/2;
    }
};
