//
//  758_bold_word.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _58_bold_word_h
#define _58_bold_word_h

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int n = S.size();
        string res = "";
        vector<bool> bold(n, false);
        for (string word : words) {
            int len = word.size();
            for (int i = 0; i <= n - len; ++i) {
                if (S[i] == word[0] && S.substr(i, len) == word) {
                    for (int j = i; j < i + len; ++j) bold[j] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (bold[i]) {
                if (i == 0 || !bold[i - 1]) res += "<b>";
                res.push_back(S[i]);
                if (i == n - 1 || !bold[i + 1]) res += "</b>";
            } else {
                res.push_back(S[i]);
            }
        }
        return res;
    }
};

#endif /* _58_bold_word_h */
