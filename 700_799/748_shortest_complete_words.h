//
//  748_shortest_complete_words.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _48_shortest_complete_words_h
#define _48_shortest_complete_words_h

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string res = "";
        int total = 0;
        unordered_map<char, int> freq;
        for (char c : licensePlate) {
            if (c >= 'a' && c <= 'z') {++freq[c]; ++total;}
            else if (c >= 'A' && c <= 'Z') {++freq[c + 32]; ++total;}
        }
        for (string word : words) {
            int cnt = total;
            unordered_map<char, int> t = freq;
            for (char c : word) {
                if (--t[c] >= 0) --cnt;
            }
            if (cnt == 0 && (res.empty() || res.size() > word.size())) {
                res = word;
            }
        }
        return res;
    }
};

#endif /* _48_shortest_complete_words_h */
