//
//  269_alien_order.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _69_alien_order_h
#define _69_alien_order_h

class Solution {
public:
    string alienOrder(vector<string>& words) {
        set<pair<char, char> > s;
        unordered_set<char> ch;
        vector<int> in(256, 0);
        queue<char> q;
        string res = "";
        for (auto a : words) ch.insert(a.begin(), a.end());
        for (int i = 0; i < words.size() - 1; ++i) {
            int mn = min(words[i].size(), words[i + 1].size()), j = 0;
            for (; j < min(words[i].size(), words[i + 1].size()); ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    s.insert(make_pair(words[i][j], words[i + 1][j]));
                    break;
                }
            }
            if (j == mn && words[i].size() > words[i + 1].size()) return "";
        }
        for (auto a : s) ++in[a.second];
        for (auto a : ch) {
            if (in[a] == 0) {
                q.push(a);
                res += a;
            }
        }
        while (!q.empty()) {
            char c = q.front(); q.pop();
            for (auto a : s) {
                if (a.first == c) {
                    --in[a.second];
                    if (in[a.second] == 0) {
                        q.push(a.second);
                        res += a.second;
                    }
                }
            }
        }
        return res.size() == ch.size() ? res : "";
    }
};

#endif /* _69_alien_order_h */
