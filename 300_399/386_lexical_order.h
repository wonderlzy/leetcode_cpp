//
//  386_lexical_order.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _86_lexical_order_h
#define _86_lexical_order_h

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; ++i) {
            helper(i, n, res);
        }
        return res;
    }
    void helper(int cur, int n, vector<int>& res) {
        if (cur > n) return;
        res.push_back(cur);
        for (int i = 0; i <= 9; ++i) {
            if (cur * 10 + i <= n) {
                helper(cur * 10 + i, n, res);
            } else break;
        }
    }
};

#endif /* _86_lexical_order_h */
