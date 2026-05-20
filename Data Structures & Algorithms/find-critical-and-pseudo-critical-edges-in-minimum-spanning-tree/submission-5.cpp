class DSU{
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findP(int node) {
        while(parent[node] != node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    bool merge(const int &u, const int &v) {
        int pu = findP(u);
        int pv = findP(v);
        if(pu == pv) return false;
        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
            rank[pv] += rank[pu];
        } else {
           parent[pv] = pu;
           rank[pu] += rank[pv]; 
        }
        return true;
    }
};
class Solution {
public:
    int findMst(const vector<vector<int>> &edges, const int &n, const int &skip, const int &force) {
        DSU dsu(n);
        int mst = 0, count = 0;
        int m = (int)edges.size();
        if(force != -1) {
            auto edge = edges[force];
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dsu.merge(u, v)) { 
                ++count;
                mst += w;
            }
        }
        for(int i = 0; i < m; i++) {
            if(skip == i) continue;
            auto edge = edges[i];
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dsu.merge(u, v)){
                mst += w;
                ++count;
            } 
        }
        return (count == n-1) ? mst : INT_MAX;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = (int)edges.size();
        for(int i = 0; i < m; i++)edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [&](const vector<int> &u, const vector<int> &v) {
            return u[2] < v[2];
        });
        int minMst = findMst(edges, n, -1, -1);
        vector<int> critical, pseudoCritical;
        for(int i = 0; i < m; i++) {
            if(findMst(edges, n, i, -1) > minMst) critical.push_back(edges[i][3]);
            else if(findMst(edges, n, -1, i) == minMst) pseudoCritical.push_back(edges[i][3]);
        }
        vector<vector<int>> results;
        results.push_back(critical);
        results.push_back(pseudoCritical);
        return results;
    }
};