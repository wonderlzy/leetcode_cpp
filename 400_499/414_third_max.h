//
//  413_third_max.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/15.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _13_third_max_h
#define _13_third_max_h

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for (int num : nums) {
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second && num < first) {
                third = second;
                second = num;
            } else if (num > third && num < second) {
                third = num;
            }
        }
        return (third == LONG_MIN || third == second) ? first : third;
    }
};

#endif /* _13_third_max_h */
