//
//  717_is_one_bits_character.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _17_is_one_bits_character_h
#define _17_is_one_bits_character_h

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(), i = 0;
        while (i < n - 1) {
            if (bits[i] == 0) ++i;
            else i+= 2;
        }
        return i == n - 1;
    }
};

#endif /* _17_is_one_bits_character_h */
