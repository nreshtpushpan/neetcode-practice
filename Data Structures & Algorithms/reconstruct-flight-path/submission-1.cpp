class Solution {
public:
    vector<string> itineary;
    void recur(unordered_map<string, multiset<string>> &g, const string &start) {
        while(!g[start].empty()) {
            auto next = g[start].begin();
            string nextDestination = *next;
            g[start].erase(next);
            recur(g, nextDestination);
        }
        itineary.push_back(start);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> g;
        for(auto ticket: tickets) {
            g[ticket[0]].insert(ticket[1]);
        }
        recur(g, "JFK");
        reverse(itineary.begin(), itineary.end());
        return itineary;
    }
};
