//
//  763_partition_letters.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _63_partition_letters_h
#define _63_partition_letters_h

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int n = S.size(), start = 0, last = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < n; ++i) m[S[i]] = i;
        for (int i = 0; i < n; ++i) {
            last = max(last, m[S[i]]);
            if (i == last) {
                res.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};

#endif /* _63_partition_letters_h */
