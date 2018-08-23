//
//  747_dominate_index.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _47_dominate_index_h
#define _47_dominate_index_h

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx = INT_MIN, secondMx = INT_MIN, mxId = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > mx) {
                secondMx = mx;
                mx = nums[i];
                mxId = i;
            } else if (nums[i] > secondMx) {
                secondMx = nums[i];
            }
        }
        return (mx - secondMx >= secondMx) ? mxId : -1;
    }
};

#endif /* _47_dominate_index_h */
