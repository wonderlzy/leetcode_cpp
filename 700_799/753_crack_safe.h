//
//  753_crack_safe.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _53_crack_safe_h
#define _53_crack_safe_h

class Solution {
public:
    string crackSafe(int n, int k) {
        string res = string(n, '0');
        unordered_set<string> visited{{res}};
        for (int i = 0; i < pow(k,n); ++i) {
            string pre = res.substr(res.size() - n + 1, n - 1);
            for (int j = k - 1; j >= 0; --j) {
                string cur = pre + to_string(j);
                if (!visited.count(cur)) {
                    visited.insert(cur);
                    res += to_string(j);
                    break;
                }
            }
        }
        return res;
    }
};

#endif /* _53_crack_safe_h */
