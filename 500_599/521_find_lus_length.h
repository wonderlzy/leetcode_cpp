//
//  521_find_lus_length.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _21_find_lus_length_h
#define _21_find_lus_length_h

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.size(), b.size());
    }
};

#endif /* _21_find_lus_length_h */
