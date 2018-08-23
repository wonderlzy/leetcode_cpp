//
//  824_to_goat_latine.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _24_to_goat_latine_h
#define _24_to_goat_latine_h

class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        istringstream iss(S);
        string res, w;
        int i = 0, j;
        while (iss >> w) {
            res += ' ' + (vowel.count(w[0]) == 1 ? w : w.substr(1) + w[0]) + "ma";
            for (j = 0, ++i; j < i; ++j) res += "a";
        }
        return res.substr(1);
    }
};

#endif /* _24_to_goat_latine_h */
