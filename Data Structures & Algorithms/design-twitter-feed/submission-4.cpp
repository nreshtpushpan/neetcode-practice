#include <chrono>
class Twitter {
private:
    struct Cmp {
        bool operator()(const pair<int,long long>& a, const pair<int,long long>& b) {
            return a.second > b.second;
        }
    };    
public:

    int maxFeedSize = 10;
    unordered_map<int, vector<pair<int, long long>>> tweetsMap;
    unordered_map<int, unordered_set<int>> followerMap;

    Twitter() {}
    
    long long getEpoch() {
        return chrono::system_clock::now().time_since_epoch().count();
    }

    void postTweet(int userId, int tweetId) {
        tweetsMap[userId].push_back({tweetId, getEpoch()});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, Cmp> pq;
        for(auto tweet : tweetsMap[userId]) {
            pq.push({tweet.first, tweet.second});
            if(pq.size() > maxFeedSize) pq.pop();
        }
        for(auto followerId : followerMap[userId]) {
            for(auto tweet : tweetsMap[followerId]) {
                pq.push({tweet.first, tweet.second});
                if(pq.size() > maxFeedSize) pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            auto tweet = pq.top();
            pq.pop();
            res.push_back(tweet.first);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followerMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        auto it = followerMap[followerId].find(followeeId);
        if(it != followerMap[followerId].end()) followerMap[followerId].erase(it);
    }
};
