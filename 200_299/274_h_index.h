//
//  274_h_index.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/7.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _74_h_index_h
#define _74_h_index_h

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); ++i) {
            if (i >= citations[i]) return i;
        }
        return citations.size();
    }
};

#endif /* _74_h_index_h */
