//
//  245_shortest_word_distance3.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _45_shortest_word_distance3_h
#define _45_shortest_word_distance3_h

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1 = words.size(), p2 = -words.size(), res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) p1 = word1 == word2 ? p2 : i;
            if (words[i] == word2) p2 = i;
            res = min(res, abs(p1 - p2));
        }
        return res;
    }
};

#endif /* _45_shortest_word_distance3_h */
