//
//  293_generate_possible_next_moves.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/7.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _93_generate_possible_next_moves_h
#define _93_generate_possible_next_moves_h

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '+' && s[i - 1] == '+') {
                res.push_back(s.substr(0, i - 1) + "--" + s.substr(i + 1));
            }
        }
        return res;
    }
};

#endif /* _93_generate_possible_next_moves_h */
