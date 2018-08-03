//
//  219_contain_nearby_duplicates.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _19_contain_nearby_duplicates_h
#define _19_contain_nearby_duplicates_h

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(nums[i]) && i - m[nums[i]] <= k) return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};

#endif /* _19_contain_nearby_duplicates_h */
