//
//  315_count_smaller.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _15_count_smaller_h
#define _15_count_smaller_h

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t;
        vector<int> res(nums.size());
        
        for(int i=nums.size()-1; i>=0; --i){
            int left = 0, right = t.size();
            while (left < right) {
                int mid = left + (right-left) / 2;
                if(t[mid] >= nums[i])
                    right = mid;
                else
                    left = mid+1;
            }
            
            res[i] = right;
            t.insert(t.begin()+right, nums[i]);
        }
        
        return res;
    }
};

#endif /* _15_count_smaller_h */
