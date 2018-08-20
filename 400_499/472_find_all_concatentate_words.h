//
//  472_find_all_concatentate_words.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _72_find_all_concatentate_words_h
#define _72_find_all_concatentate_words_h

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        if (words.size() <= 2) return {};
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end());
        for (string word : words) {
            dict.erase(word);
            int len = word.size();
            if (len == 0) continue;
            vector<bool> v(len + 1, false);
            v[0] = true;
            for (int i = 0; i < len + 1; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (v[j] && dict.count(word.substr(j, i - j))) {
                        v[i] = true;
                        break;
                    }
                }
            }
            if (v.back()) res.push_back(word);
            dict.insert(word);
        }
        return res;
    }
};

#endif /* _72_find_all_concatentate_words_h */
