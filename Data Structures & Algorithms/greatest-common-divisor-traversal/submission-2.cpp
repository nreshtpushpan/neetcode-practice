class DSU {
    unordered_map<int, int> parent, rank;
public:
    DSU() {}
    
    int findP(int node) {
        auto it = parent.find(node);
        if(it == parent.end()) parent[node] = node;
        if(parent[node] == node) return node;
        return parent[node] = findP(parent[node]);
    }

    bool merge(const int &a, const int &b) {
        int pa = findP(a);
        int pb = findP(b);
        if(pa == pb) return false;
        auto ra = rank.find(pa);
        if(ra == rank.end()) rank[pa] = 1;
        auto rb = rank.find(pb);
        if(rb == rank.end()) rank[pb] = 1;
        if(rank[pa] < rank[pb]) {
            parent[pa] = pb;
            rank[pb] += rank[pa];
        } else {
            parent[pb] = pa;
            rank[pa] += rank[pb];
        }
        return true;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 1) return true;
        for(int i = 0; i < n; i++)
            if(nums[i] == 1) return false;
        DSU dsu;
        int count = 0;
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            for(int prime = 2; prime <= num; prime++) {
                if(num%prime == 0) {
                    while(num > 1 && num%prime == 0) num /= prime;
                    dsu.merge(nums[i], prime);
                }
            }
        }
        int pa = dsu.findP(nums[0]);
        for(int i = 1; i < n; i++) {
            int pb = dsu.findP(nums[i]);
            if(pa != pb) return false;
        }
        return true;
        
    }

};