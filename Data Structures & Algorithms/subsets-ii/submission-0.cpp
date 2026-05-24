class Solution {
public:
    int N;
    vector<vector<int>> results;
    set<vector<int>> resultSet;
    void recur(const vector<int> &nums, vector<int> &cur, int index) {
        if(index == N) {
            resultSet.insert(cur);
            return;
        }
        recur(nums, cur, index+1);
        for(int i = index; i < N; i++) {
            if(i > index && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            recur(nums, cur, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        N = (int)nums.size();
        vector<int> cur;
        sort(nums.begin(), nums.end());
        recur(nums, cur, 0);
        for(auto vec : resultSet) results.push_back(vec);
        return results;
    }
};
