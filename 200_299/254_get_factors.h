//
//  254_get_factors.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _54_get_factors_h
#define _54_get_factors_h

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                vector<vector<int>> v = getFactors(n / i);
                vector<int> out{i, n / i};
                res.push_back(out);
                for (auto a : v) {
                    if (i <= a[0]) {
                        a.insert(a.begin(), i);
                        res.push_back(a);
                    }
                }
            }
        }
        return res;
    }
};

#endif /* _54_get_factors_h */
