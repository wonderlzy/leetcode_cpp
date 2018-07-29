//
//  128_longest_consecutive.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/29.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _28_longest_consecutive_h
#define _28_longest_consecutive_h

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        int pre = 0, next = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(auto num : nums){
            if(!s.count(num))
                continue;
            s.erase(num);
            pre = num - 1;
            next = num + 1;
            
            while(s.count(pre))
                s.erase(pre--);
            while(s.count(next))
                s.erase(next++);
            
            res = max(res, next-pre-1);
        }
        
        return res;
    }
};

#endif /* _28_longest_consecutive_h */
