//
//  810_xor_game.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _10_xor_game_h
#define _10_xor_game_h

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int x = 0, n = nums.size();
        for (int num : nums) x ^= num;
        return x == 0 || n % 2 == 0;
    }
};

#endif /* _10_xor_game_h */
