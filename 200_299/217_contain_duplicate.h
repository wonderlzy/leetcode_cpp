//
//  217_contain_duplicate.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _17_contain_duplicate_h
#define _17_contain_duplicate_h

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto num : nums){
            if(m.count(num)) return true;
            ++m[num];
        }
        
        return false;
    }
};

#endif /* _17_contain_duplicate_h */
