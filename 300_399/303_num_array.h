//
//  303_num_array.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _03_num_array_h
#define _03_num_array_h

class NumArray {
public:
    NumArray(vector<int> nums) {
        dp = nums;
        for(int i=1; i<nums.size(); ++i)
            dp[i] += dp[i-1];
    }
    
    int sumRange(int i, int j) {
        
        return i==0 ? dp[j] : dp[j]-dp[i-1];
    }
    
private:
    vector<int> dp;
};

#endif /* _03_num_array_h */
