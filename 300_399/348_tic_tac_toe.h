//
//  348_tic_tac_toe.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _48_tic_tac_toe_h
#define _48_tic_tac_toe_h

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n): rows(n), cols(n), N(n), diag(0), rev_diag(0) {}
    
    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1;
        rows[row] += add;
        cols[col] += add;
        diag += (row == col ? add : 0);
        rev_diag += (row == N - col - 1 ? add : 0);
        return (abs(rows[row]) == N || abs(cols[col]) == N || abs(diag) == N || abs(rev_diag) == N) ? player : 0;
    }
    
private:
    vector<int> rows, cols;
    int diag, rev_diag, N;
};

#endif /* _48_tic_tac_toe_h */
