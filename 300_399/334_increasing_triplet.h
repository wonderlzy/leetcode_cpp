//
//  334_increasing_triplet.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _34_increasing_triplet_h
#define _34_increasing_triplet_h

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        for(auto num : nums){
            if(m1 >= num)
                m1 = num;
            else if(m2 >= num)
                m2 = num;
            else
                return true;
        }
        return false;
    }
};

#endif /* _34_increasing_triplet_h */
