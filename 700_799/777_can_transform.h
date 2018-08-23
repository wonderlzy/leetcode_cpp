//
//  777_can_transform.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _77_can_transform_h
#define _77_can_transform_h

class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size(), i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == 'X') ++i;
            while (j < n && end[j] == 'X') ++j;
            if (start[i] != end[j]) return false;
            if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) return false;
            ++i; ++j;
        }
        return true;
    }
};

#endif /* _77_can_transform_h */
