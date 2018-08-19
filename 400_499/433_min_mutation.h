//
//  433_min_mutation.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _33_min_mutation_h
#define _33_min_mutation_h

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (bank.empty()) return -1;
        vector<char> gens{'A','C','G','T'};
        unordered_set<string> s{bank.begin(), bank.end()};
        unordered_set<string> visited;
        queue<string> q{{start}};
        int level = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                string t = q.front(); q.pop();
                if (t == end) return level;
                for (int j = 0; j < t.size(); ++j) {
                    char old = t[j];
                    for (char c : gens) {
                        t[j] = c;
                        if (s.count(t) && !visited.count(t)) {
                            visited.insert(t);
                            q.push(t);
                        }
                    }
                    t[j] = old;
                }
            }
            ++level;
        }
        return -1;
    }
};

#endif /* _33_min_mutation_h */
