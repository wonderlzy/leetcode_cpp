//
//  383_can_construct.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _83_can_construct_h
#define _83_can_construct_h

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (char c : magazine) ++m[c];
        for (char c : ransomNote) {
            if (--m[c] < 0) return false;
        }
        return true;
    }
};

#endif /* _83_can_construct_h */
