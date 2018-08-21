//
//  527_word_abbreviation.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _27_word_abbreviation_h
#define _27_word_abbreviation_h

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<string> res(n);
        vector<int> pre(n, 1);
        for (int i = 0; i < n; ++i) {
            res[i] = abbreviate(dict[i], pre[i]);
        }
        for (int i = 0; i < n; ++i) {
            while (true) {
                set<int> s;
                for (int j = i + 1; j < n; ++j) {
                    if (res[j] == res[i]) s.insert(j);
                }
                if (s.empty()) break;
                s.insert(i);
                for (auto a : s) {
                    res[a] = abbreviate(dict[a], ++pre[a]);
                }
            }
        }
        return res;
    }
    string abbreviate(string s, int k) {
        return (k >= s.size() - 2) ? s : s.substr(0, k) + to_string(s.size() - k - 1) + s.back();
    }
};

#endif /* _27_word_abbreviation_h */
