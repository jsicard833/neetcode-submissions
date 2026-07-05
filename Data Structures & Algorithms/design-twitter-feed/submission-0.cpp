class Twitter {
public:
    Twitter() : time(0) {}
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto compare = [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> heap(compare);

        followMap[userId].insert(userId);
        for (auto followeeId: followMap[userId]) {
            if (tweetMap.count(followeeId)) {
                const auto& tweets = tweetMap[followeeId];
                int index = tweets.size() - 1;
                heap.push({tweets[index][0], tweets[index][1], followeeId, index});
            }
        }

        while (!heap.empty() && res.size() < 10) {
            auto curr = heap.top();
            heap.pop();
            res.push_back(curr[1]);
            auto index = curr[3];
            if (index > 0) {
                const auto& tweet = tweetMap[curr[2]][index - 1];
                heap.push({tweet[0], tweet[1], curr[2], index - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }

private:
    unordered_map<int, vector<vector<int>>> tweetMap;
    unordered_map<int, set<int>> followMap;
    int time;
};
