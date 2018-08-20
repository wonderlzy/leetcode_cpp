//
//  467_find_substring_inwrapround_string.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _67_find_substring_inwrapround_string_h
#define _67_find_substring_inwrapround_string_h

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> cnt(26, 0);
        int len = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (i > 0 && (p[i] == p[i - 1] + 1 || p[i - 1] - p[i] == 25)) {
                ++len;
            } else {
                len = 1;
            }
            cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], len);
        }
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};

#endif /* _67_find_substring_inwrapround_string_h */
