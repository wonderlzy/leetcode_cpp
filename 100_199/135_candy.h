//
//  135_candy.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _35_candy_h
#define _35_candy_h

class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;
        
        int res = 0, n = ratings.size();
        vector<int> nums(n, 1);
        
        for(int i=0; i<n-1; ++i){
            if(ratings[i+1] > ratings[i])
                nums[i+1] = nums[i] + 1;
        }
        
        for(int j=n-1; j>0; --j){
            if(ratings[j-1] > ratings[j])
                nums[j-1] = max(nums[j-1], nums[j]+1);
        }
        
        for(auto num : nums)
            res += num;
        
        return res;
    }
};

#endif /* _35_candy_h */
