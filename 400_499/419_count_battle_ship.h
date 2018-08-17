//
//  419_count_battle_ship.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/16.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _19_count_battle_ship_h
#define _19_count_battle_ship_h

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        int res = 0, m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.' || (i > 0 && board[i - 1][j] == 'X') || (j > 0 && board[i][j - 1] == 'X')) continue;
                ++res;
            }
        }
        return res;
    }
};

#endif /* _19_count_battle_ship_h */
