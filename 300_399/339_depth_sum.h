//
//  339_depth_sum.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _39_depth_sum_h
#define _39_depth_sum_h

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return helper(nestedList, 1);
    }
    int helper(vector<NestedInteger>& nl, int depth) {
        int res = 0;
        for (auto a : nl) {
            res += a.isInteger() ? a.getInteger() * depth : helper(a.getList(), depth + 1);
        }
        return res;
    }
};

#endif /* _39_depth_sum_h */
