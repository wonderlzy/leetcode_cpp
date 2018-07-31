//
//  167_two_sum.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _67_two_sum_h
#define _67_two_sum_h

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() < 2) return {};
        int left = 0, right = numbers.size() - 1;
        
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target)
                return {left+1, right+1};
            else if(sum > target)
                --right;
            else
                ++left;
        }
        
        return {};
    }
};

#endif /* _67_two_sum_h */
