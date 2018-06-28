//
//  41_first_missing_postive.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/26.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _1_first_missing_postive_h
#define _1_first_missing_postive_h

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;
        bucketSort(nums);
        
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] != i+1)
                return i+1;
        }
        
        return nums.size()+1;
    }
    
private:
    void bucketSort(vector<int>& nums){
        for(int i=0; i<nums.size(); ++i){
            while(nums[i] != i+1){
                if(nums[i]<=0 || nums[i]==nums[nums[i]-1] || nums[i]>nums.size())
                    break;
                swap(nums[i], nums[nums[i]-1]);
            }
        }
    }
};

#endif /* _1_first_missing_postive_h */
