class CountSquares {
public:
    map<pair<int,int>, int> mp;
    unordered_map<int, unordered_set<int>> xAxis, yAxis;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        mp[{x,y}]++;
        xAxis[x].insert(y);
        yAxis[y].insert(x);
    }
    
    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int res = 0;
        for(auto y2 : xAxis[x1]) {
            int dis = abs(y2-y1);
            if(dis == 0) continue;
            res += mp[{x1-dis, y2}] * mp[{x1-dis, y1}] * mp[{x1,y2}] ;
            res += mp[{x1+dis, y2}] * mp[{x1+dis, y1}] * mp[{x1,y2}];
        }
        return res;
    }
};
