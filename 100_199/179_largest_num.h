//
//  179_largest_num.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _79_largest_num_h
#define _79_largest_num_h

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a)+to_string(b) > to_string(b) + to_string(a);
        });
        
        for(auto num : nums)
            res += to_string(num);
        
        return res[0]=='0' ? "0" : res;
    }
};

#endif /* _79_largest_num_h */
