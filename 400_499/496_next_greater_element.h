//
//  496_next_greater_element.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _96_next_greater_element_h
#define _96_next_greater_element_h

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ret(findNums.size(), -1);
        unordered_map<int,int> mp(nums.size() * 2);
        stack<int> sta;
        for(const auto & x:nums){
            while(!sta.empty() && x > sta.top())
                mp[sta.top()] = x, sta.pop();
            sta.push(x);
        }
        for(int i = 0; i < findNums.size(); i++)
            if(mp.find(findNums[i]) != mp.end())
                ret[i] = mp[findNums[i]];
        return ret;
    }
};

#endif /* _96_next_greater_element_h */
