//
//  355_twitter.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _55_twitter_h
#define _55_twitter_h

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        cnt = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        tweets[userId].insert({cnt++, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        map<int, int> top10;
        for(auto it : friends[userId]){
            for(auto a : tweets[it]){
                top10.insert({a.first, a.second});
                if(top10.size() > 10)
                    top10.erase(top10.begin());
            }
        }
        
        for(auto it = top10.rbegin(); it != top10.rend(); ++it)
            res.push_back(it->second);
        
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followeeId != followerId){
            friends[followerId].erase(followeeId);
        }
    }
private:
    int cnt = 0;
    unordered_map<int, set<int>> friends;
    unordered_map<int, map<int, int>> tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

#endif /* _55_twitter_h */
