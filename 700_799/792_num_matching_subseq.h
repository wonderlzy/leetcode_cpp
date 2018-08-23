//
//  792_num_matching_subseq.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _92_num_matching_subseq_h
#define _92_num_matching_subseq_h

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int res = 0, n = S.size();
        unordered_set<string> pass, out;
        for (string word : words) {
            if (pass.count(word) || out.count(word)) {
                if (pass.count(word)) ++res;
                continue;
            }
            int i = 0, j = 0, m = word.size();
            while (i < n && j < m) {
                if (word[j] == S[i]) ++j;
                ++i;
            }
            if (j == m) {++res; pass.insert(word);}
            else out.insert(word);
        }
        return res;
    }
};

#endif /* _92_num_matching_subseq_h */
