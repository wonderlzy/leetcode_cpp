//
//  389_find_difference.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _89_find_difference_h
#define _89_find_difference_h

class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for(auto c : s) res ^= c;
        for(auto c : t) res ^= c;
        
        return res;
    }
};

#endif /* _89_find_difference_h */
