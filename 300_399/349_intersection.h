//
//  349_intersection.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _49_intersection_h
#define _49_intersection_h

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(), nums1.end()), res;
        for(auto num : nums2){
            if(s.count(num))
                res.insert(num);
        }
        
        return vector<int>(res.begin(), res.end());
    }
};

#endif /* _49_intersection_h */
