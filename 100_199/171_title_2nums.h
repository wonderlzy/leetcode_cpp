//
//  171_title_2nums.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _71_title_2nums_h
#define _71_title_2nums_h

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        
        for(auto da : s){
            res = res * 26 + (da-'A' + 1);
        }
        
        return res;
    }
};

#endif /* _71_title_2nums_h */
