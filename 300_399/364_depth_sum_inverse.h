//
//  364_depth_sum_inverse.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _64_depth_sum_inverse_h
#define _64_depth_sum_inverse_h

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int unweighted = 0, weighted = 0;
        while (!nestedList.empty()) {
            vector<NestedInteger> nextLevel;
            for (auto a : nestedList) {
                if (a.isInteger()) {
                    unweighted += a.getInteger();
                } else {
                    nextLevel.insert(nextLevel.end(), a.getList().begin(), a.getList().end());
                }
            }
            weighted += unweighted;
            nestedList = nextLevel;
        }
        return weighted;
    }
}; 

#endif /* _64_depth_sum_inverse_h */
