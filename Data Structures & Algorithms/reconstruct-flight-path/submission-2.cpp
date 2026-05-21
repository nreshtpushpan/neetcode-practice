class Solution {
public:
    vector<string> itineary;
    void recur(unordered_map<string, priority_queue<string, vector<string>, greater<>>> &g, const string &start) {
        while(!g[start].empty()) {
            auto nextDestination = g[start].top();
            g[start].pop();
            recur(g, nextDestination);
        }
        itineary.push_back(start);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<>>> g;
        for(auto ticket: tickets) {
            g[ticket[0]].push(ticket[1]);
        }
        recur(g, "JFK");
        reverse(itineary.begin(), itineary.end());
        return itineary;
    }
};
