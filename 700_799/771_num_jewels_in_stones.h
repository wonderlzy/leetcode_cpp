//
//  771_num_jewels_in_stones.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _71_num_jewels_in_stones_h
#define _71_num_jewels_in_stones_h

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_set<char> s;
        for (char c : J) s.insert(c);
        for (char c : S) {
            if (s.count(c)) ++res;
        }
        return res;
    }
};

#endif /* _71_num_jewels_in_stones_h */
