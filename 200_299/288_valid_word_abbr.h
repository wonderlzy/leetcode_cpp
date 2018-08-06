//
//  288_valid_word_abbr.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/7.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _88_valid_word_abbr_h
#define _88_valid_word_abbr_h

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto a : dictionary) {
            string k = a[0] + to_string(a.size() - 2) + a.back();
            m[k].insert(a);
        }
    }
    bool isUnique(string word) {
        string k = word[0] + to_string(word.size() - 2) + word.back();
        return m[k].count(word) == m[k].size();
    }
private:
    unordered_map<string, set<string>> m;
};

#endif /* _88_valid_word_abbr_h */
