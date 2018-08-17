//
//  418_word_typing.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/16.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _18_word_typing_h
#define _18_word_typing_h

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string all = "";
        for (string word : sentence) all += (word + " ");
        int start = 0, len = all.size();
        for (int i = 0; i < rows; ++i) {
            start += cols;
            if (all[start % len] == ' ') {
                ++start;
            } else {
                while (start > 0 && all[(start - 1) % len] != ' ') {
                    --start;
                }
            }
        }
        return start / len;
    }
};

#endif /* _18_word_typing_h */
