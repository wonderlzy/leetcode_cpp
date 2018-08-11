//
//  300_length_of_lis.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/8.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _00_length_of_lis_h
#define _00_length_of_lis_h

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> end{nums[0]};
        for(auto num : nums){
            if(num < end[0])
                end[0] = num;
            else if(num > end.back())
                end.push_back(num);
            
            else {
                int left = 0, right = end.size();
                while(left < right){
                    int mid = left + (right-left) / 2;
                    if(end[mid] < num)
                        left = mid+1;
                    else
                        right = mid;
                }
                end[right] = num;
            }
        }
        
        return end.size();
        
        /*
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for(int i=0; i<nums.size(); ++i){
            for(int j=0; j<i; ++j){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        
        return res;
        */
    }
};

#endif /* _00_length_of_lis_h */
