//
//  462_min_move2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _62_min_move2_h
#define _62_min_move2_h

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res = 0, i = 0, j = (int)nums.size() - 1;
        sort(nums.begin(), nums.end());
        while (i < j) {
            res += nums[j--] - nums[i++];
        }
        return res;
    }
};

#endif /* _62_min_move2_h */
