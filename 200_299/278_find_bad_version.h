//
//  278_find_bad_version.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/7.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _78_find_bad_version_h
#define _78_find_bad_version_h

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid + 1)) right = mid;
            else left = mid + 1;
        }
        return right + 1;
    }
};

#endif /* _78_find_bad_version_h */
