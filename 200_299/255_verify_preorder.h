//
//  255_verify_preorder.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _55_verify_preorder_h
#define _55_verify_preorder_h

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        stack<int> s;
        for (auto a : preorder) {
            if (a < low) return false;
            while (!s.empty() && a > s.top()) {
                low = s.top(); s.pop();
            }
            s.push(a);
        }
        return true;
    }
};

#endif /* _55_verify_preorder_h */
