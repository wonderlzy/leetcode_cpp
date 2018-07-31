//
//  164_maximun_gap.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _64_maximun_gap_h
#define _64_maximun_gap_h

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // the max gaps will never be gaps in one bucket because of the drawer principle
        if(nums.size() < 2) return 0;
        int mx = INT_MIN, mn = INT_MAX;
        const size_t n = nums.size();
        
        for(auto num : nums){
            mx = max(mx, num);
            mn = min(mn, num);
        }
        
        int size = (mx - mn) / n + 1;
        int bucketNums = (mx -mn) / size + 1;
        
        vector<int> bucketMin(bucketNums, INT_MAX);
        vector<int> bucketMax(bucketNums, INT_MIN);
        set<int> s;
        
        for(auto num : nums){
            int idx = (num - mn) / size;
            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
            
            s.insert(idx);
        }
        
        int pre = 0, res = 0;
        for(int i=1; i<bucketNums; ++i){
            if(!s.count(i)) continue;
            res = max(res, bucketMin[i]-bucketMax[pre]);
            pre = i;
        }
        
        return res;
    }
};

#endif /* _64_maximun_gap_h */
