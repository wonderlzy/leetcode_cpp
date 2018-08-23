//
//  720_longest_words.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _20_longest_words_h
#define _20_longest_words_h

class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        unordered_set<string> s;
        sort(words.begin(), words.end());
        for (string word : words) {
            if (word.size() == 1 || s.count(word.substr(0, word.size() - 1))) {
                res = (word.size() > res.size()) ? word : res;
                s.insert(word);
            }
        }
        return res;
    }
};

#endif /* _20_longest_words_h */
