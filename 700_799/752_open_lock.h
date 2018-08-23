//
//  752_open_lock.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _52_open_lock_h
#define _52_open_lock_h

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadlock(deadends.begin(), deadends.end());
        if (deadlock.count("0000")) return -1;
        int res = 0;
        unordered_set<string> visited{{"0000"}};
        queue<string> q{{"0000"}};
        while (!q.empty()) {
            ++res;
            for (int k = q.size(); k > 0; --k) {
                auto t = q.front(); q.pop();
                for (int i = 0; i < t.size(); ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if (j == 0) continue;
                        string str = t;
                        str[i] = ((t[i] - '0') + 10 + j) % 10 + '0';
                        if (str == target) return res;
                        if (!visited.count(str) && !deadlock.count(str)) q.push(str);
                        visited.insert(str);
                    }
                }
            }
        }
        return -1;
    }
};

#endif /* _52_open_lock_h */
