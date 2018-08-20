//
//  453_min_move.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _53_min_move_h
#define _53_min_move_h

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = INT_MAX, res = 0;
        for (int num : nums) mn = min(mn, num);
        for (int num : nums) res += num - mn;
        return res;
    }
};

#endif /* _53_min_move_h */
