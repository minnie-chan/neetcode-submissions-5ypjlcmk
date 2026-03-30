class Twitter {
public:
    int timer;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int,int>>> tweets;

    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> allTweets;

        // user's own tweets
        for (auto &tweet : tweets[userId]) {
            allTweets.push_back(tweet);
        }

        // followed users' tweets
        for (int followee : follows[userId]) {
            for (auto &tweet : tweets[followee]) {
                allTweets.push_back(tweet);
            }
        }

        sort(allTweets.begin(), allTweets.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        vector<int> feed;
        for (int i = 0; i < allTweets.size() && i < 10; i++) {
            feed.push_back(allTweets[i].second);
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};