//
//  529_update_board.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _29_update_board_h
#define _29_update_board_h

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty() || board[0].empty()) return {};
        int m = board.size(), n = board[0].size(), row = click[0], col = click[1], cnt = 0;
        if (board[row][col] == 'M') {
            board[row][col] = 'X';
        } else {
            vector<vector<int>> neighbors;
            for (int i = -1; i < 2; ++i) {
                for (int j = -1; j < 2; ++j) {
                    int x = row + i, y = col + j;
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    if (board[x][y] == 'M') ++cnt;
                    else if (cnt == 0 && board[x][y] == 'E') neighbors.push_back({x, y});
                }
            }
            if (cnt > 0) {
                board[row][col] = cnt + '0';
            } else {
                for (auto a : neighbors) {
                    board[a[0]][a[1]] = 'B';
                    updateBoard(board, a);
                }
            }
        }
        return board;
    }
};

#endif /* _29_update_board_h */
