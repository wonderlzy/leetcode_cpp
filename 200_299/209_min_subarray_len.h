//
//  209_min_subarray_len.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _09_min_subarray_len_h
#define _09_min_subarray_len_h

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        const size_t n = nums.size();
        int left = 0, right = 0, sum = 0, res = n + 1;
        while(right < n){
            while(sum < s && right < n){
                sum += nums[right++];
            }
            while(sum >= s){
                res = min(res, right-left);
                sum -= nums[left++];
            }
        }
        
        return res==n+1 ? 0 : res;
    }
};

#endif /* _09_min_subarray_len_h */
