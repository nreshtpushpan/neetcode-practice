class Solution {
public:
    vector<string> itineary;
    map<pair<string, string> , int> visit;
    void recur(unordered_map<string, vector<string>> &g, const string &start) {
        for(auto next : g[start]) {
            if(visit[{start, next}] == 0) continue;
            visit[{start, next}]--;
            recur(g, next);
        }
        itineary.push_back(start);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end(), [&](const vector<string> &a, const vector<string> &b) {
            return a[1] < b[1];
        });
        unordered_map<string, vector<string>> g;
        for(auto ticket: tickets) {
            g[ticket[0]].push_back(ticket[1]);
            visit[{ticket[0], ticket[1]}]++;
        }
        recur(g, "JFK");
        reverse(itineary.begin(), itineary.end());
        return itineary;
    }
};
