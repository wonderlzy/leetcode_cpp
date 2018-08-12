//
//  344_reverse_string.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _44_reverse_string_h
#define _44_reverse_string_h

class Solution {
public:
    string reverseString(string s) {
        int left = 0, right = s.size()-1;
        while(left < right)
            swap(s[left++], s[right--]);
        
        return s;
    }
};

#endif /* _44_reverse_string_h */
