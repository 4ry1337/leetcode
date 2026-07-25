#include <bits/stdc++.h>

using namespace std;

/* https://leetcode.com/problems/design-twitter */

class Twitter {
 private:
  int counter = 0;
  unordered_map<int, vector<pair<int, int>>> m_tweets;
  unordered_map<int, unordered_set<int>> m_follows;

 public:
  Twitter() {}

  void postTweet(int userId, int tweetId) {
    m_tweets[userId].push_back({counter++, tweetId});
  }

  vector<int> getNewsFeed(int userId) {
    priority_queue<pair<int, int>> feed;
    for (auto& followee : m_follows[userId]) {
      for (auto& [counter, tweet] : m_tweets[followee]) {
        feed.push({counter, tweet});
        if (feed.size() > 10) feed.pop();
      }
    }
    vector<int> res;
    while (!feed.empty()) {
      res.push_back(feed.top().second);
      feed.pop();
    }
    return res;
  }

  void follow(int followerId, int followeeId) {
    if (followeeId == followerId) return;
    m_follows[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    m_follows[followerId].erase(followeeId);
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
