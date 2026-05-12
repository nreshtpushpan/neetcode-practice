class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = (int)senate.size();
        set<int> r,d;
        queue<int> players;
        for(int i = 0; i < n; i++) {
            if(senate[i] == 'R') r.insert(i);
            else d.insert(i);
            players.push(i);
        }
        vector<int> eliminated(n, false);
        while(!r.empty() && !d.empty()) {
            auto playerIndex = players.front();
            players.pop();
            if(eliminated[playerIndex]) continue;
            cout<<senate[playerIndex]<<endl;
            if(senate[playerIndex] == 'R') {
                if(d.empty()) return "Radiant";
                auto nextPlayer = d.upper_bound(playerIndex);
                if(nextPlayer == d.end()) nextPlayer = d.begin();
                eliminated[*nextPlayer] = true;
                d.erase(nextPlayer);
            } else {
                if(r.empty()) return "Dire";
                auto nextPlayer = r.upper_bound(playerIndex);
                if(nextPlayer == r.end()) nextPlayer = r.begin();
                eliminated[*nextPlayer] = true;
                r.erase(nextPlayer);
            }
            players.push(playerIndex);
        }
        return (!r.empty()) ? "Radiant" : "Dire";
    }
};