//
//  616_add_bold_tags.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _16_add_bold_tags_h
#define _16_add_bold_tags_h

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        string res = "";
        int n = s.size();
        unordered_set<int> bold;
        for (string word : dict) {
            int len = word.size();
            for (int i = 0; i <= n - len; ++i) {
                if (s[i] == word[0] && s.substr(i, len) == word) {
                    for (int j = i; j < i + len; ++j) bold.insert(j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (bold.count(i) && !bold.count(i - 1)) res += "<b>";
            res += s[i];
            if (bold.count(i) && !bold.count(i + 1)) res += "</b>";
        }
        return res;
    }
};

#endif /* _16_add_bold_tags_h */
