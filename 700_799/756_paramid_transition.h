//
//  756_paramid_transition.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _56_paramid_transition_h
#define _56_paramid_transition_h

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, unordered_set<char>> m;
        for (string str : allowed) {
            m[str.substr(0, 2)].insert(str[2]);
        }
        return helper(bottom, "", m);
    }
    bool helper(string cur, string above, unordered_map<string, unordered_set<char>>& m) {
        if (cur.size() == 2 && above.size() == 1) return true;
        if (above.size() == cur.size() - 1) return helper(above, "", m);
        int pos = above.size();
        string base = cur.substr(pos, 2);
        if (m.count(base)) {
            for (char ch : m[base]) {
                if (helper(cur, above + string(1, ch), m)) {
                    return true;
                }
            }
        }
        return false;
    }
};

#endif /* _56_paramid_transition_h */
