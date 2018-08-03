//
//  220_contain_nearby_almost_duplicate.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/3.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _20_contain_nearby_almost_duplicate_h
#define _20_contain_nearby_almost_duplicate_h

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int j = 0;
        for(int i=0; i<nums.size(); ++i){
            if(i-j > k) m.erase(nums[j++]);
            
            auto a = m.lower_bound((long long) nums[i] - t);
            if(a!=m.end() && abs(a->first-nums[i]) <= t)
                return true;
            m[nums[i]] = i;
        }
        
        return false;
    }
};

#endif /* _20_contain_nearby_almost_duplicate_h */
