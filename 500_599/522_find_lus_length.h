//
//  522_find_lus_length.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _22_find_lus_length_h
#define _22_find_lus_length_h

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        unordered_set<string> s;
        sort(strs.begin(), strs.end(), [](string a, string b){
            if (a.size() == b.size()) return a > b;
            return a.size() > b.size();
        });
        for (int i = 0; i < n; ++i) {
            if (i == n - 1 || strs[i] != strs[i + 1]) {
                bool found = true;
                for (auto a : s) {
                    int j = 0;
                    for (char c : a) {
                        if (c == strs[i][j]) ++j;
                        if (j == strs[i].size()) break;
                    }
                    if (j == strs[i].size()) {
                        found = false;
                        break;
                    }
                }
                if (found) return strs[i].size();
            }
            s.insert(strs[i]);
        }
        return -1;
    }
};

#endif /* _22_find_lus_length_h */
