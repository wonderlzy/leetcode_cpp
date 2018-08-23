//
//  794_valid_tic_tac_toe.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _94_valid_tic_tac_toe_h
#define _94_valid_tic_tac_toe_h

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        bool xwin = false, owin = false;
        vector<int> row(3), col(3);
        int diag = 0, antidiag = 0, turns = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'X') {
                    ++row[i]; ++col[j]; ++turns;
                    if (i == j) ++diag;
                    if (i + j == 2) ++antidiag;
                } else if (board[i][j] == 'O') {
                    --row[i]; --col[j]; --turns;
                    if (i == j) --diag;
                    if (i + j == 2) --antidiag;
                }
            }
        }
        xwin = row[0] == 3 || row[1] == 3 || row[2] == 3 ||
        col[0] == 3 || col[1] == 3 || col[2] == 3 ||
        diag == 3 || antidiag == 3;
        owin = row[0] == -3 || row[1] == -3 || row[2] == -3 ||
        col[0] == -3 || col[1] == -3 || col[2] == -3 ||
        diag == -3 || antidiag == -3;
        if ((xwin && turns == 0) || (owin && turns == 1)) return false;
        return (turns == 0 || turns == 1) && (!xwin || !owin);
    }
};

#endif /* _94_valid_tic_tac_toe_h */
