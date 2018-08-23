//
//  822_flip_game.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _22_flip_game_h
#define _22_flip_game_h

class Solution {
public:
    int flipgame(vector<int>& f, vector<int>& b) {
        unordered_set<int> same;
        for (int i = 0; i < f.size(); ++i) if (f[i] == b[i]) same.insert(f[i]);
        int res = 3000;
        for (int & i : f) if (same.count(i) == 0) res = min(res, i);
        for (int & i : b) if (same.count(i) == 0) res = min(res, i);
        return res % 3000;
    }
};

#endif /* _22_flip_game_h */
