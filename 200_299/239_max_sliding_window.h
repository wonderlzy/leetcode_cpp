//
//  239_max_sliding_window.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _39_max_sliding_window_h
#define _39_max_sliding_window_h

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for(int i=0; i<nums.size(); ++i){
            if(!q.empty() && q.front() == i-k) q.pop_front();
            while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back();
            q.push_back(i);
            
            if(i >= k-1)
                res.push_back(nums[q.front()]);
        }
        
        return res;
    }
};

#endif /* _39_max_sliding_window_h */
