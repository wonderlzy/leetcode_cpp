//
//  350_intersection2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _50_intersection2_h
#define _50_intersection2_h

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> res;
        for(auto num : nums1)
            ++m[num];
        
        for(auto num : nums2){
            if(m[num]-- > 0)
                res.push_back(num);
        }
        
        return res;
    }
};

#endif /* _50_intersection2_h */
