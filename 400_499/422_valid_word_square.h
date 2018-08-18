//
//  422_valid_word_square.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/17.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _22_valid_word_square_h
#define _22_valid_word_square_h

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if (words.empty()) return true;
        if (words.size() != words[0].size()) return false;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                if (j >= words.size() || i >= words[j].size() || words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif /* _22_valid_word_square_h */
