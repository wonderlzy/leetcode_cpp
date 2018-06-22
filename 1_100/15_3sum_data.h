//
//  15_3sum_data.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _5_3sum_data_h
#define _5_3sum_data_h

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;
       
        sort(nums.begin(), nums.end());
        const int target = 0;
        auto last = nums.end();
        
        for(auto i=nums.begin(); i<last-2; i++){
            auto j = i+1;
            if(i>nums.begin() && *i == *(i-1))
                continue;
            auto k = last-1;
            while(j<k){
                if(*i + *j + *k < target){
                    j++;
                    while(*j == *(j-1) && j<k) j++;
                }
                else if(*i + *j + *k > target){
                    k--;
                    while (*k == *(k+1) && j<k) k--;
                }
                else{//add element
                    result.push_back(vector<int>({*i, *j, *k}));
                    j++;
                    k--;
                    while(*j==*(j-1) && *k==*(k+1) && j<k)
                        j++;
                }
            }
        }
        
        return result;
    }
};

#endif /* _5_3sum_data_h */
