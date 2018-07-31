//
//  169_majority_element.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _69_majority_element_h
#define _69_majority_element_h

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res =0, cnt = 0;
        
        for(auto num : nums){
            if(cnt == 0){
                res = num;
                ++cnt;
            } else {
                (num == res) ? ++cnt : --cnt;
            }
        }
        
        return res;
    }
};

#endif /* _69_majority_element_h */
