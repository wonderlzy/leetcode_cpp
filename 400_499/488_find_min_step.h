//
//  488_find_min_step.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _88_find_min_step_h
#define _88_find_min_step_h

class Solution {
public:
    int findMinStep(string board, string hand) {
        int res = INT_MAX;
        unordered_map<char, int> m;
        for (char c : hand) ++m[c];
        res = helper(board, m);
        return res == INT_MAX ? -1 : res;
    }
    int helper(string board, unordered_map<char, int>& m) {
        board = removeConsecutive(board);
        if (board.empty()) return 0;
        int cnt = INT_MAX, j = 0;
        for (int i = 0; i <= board.size(); ++i) {
            if (i < board.size() && board[i] == board[j]) continue;
            int need = 3 - (i - j);
            if (m[board[j]] >= need) {
                m[board[j]] -= need;
                int t = helper(board.substr(0, j) + board.substr(i), m);
                if (t != INT_MAX) cnt = min(cnt, t + need);
                m[board[j]] += need;
            }
            j = i;
        }
        return cnt;
    }
    string removeConsecutive(string board) {
        for (int i = 0, j = 0; i <= board.size(); ++i) {
            if (i < board.size() && board[i] == board[j]) continue;
            if (i - j >= 3) return removeConsecutive(board.substr(0, j) + board.substr(i));
            else j = i;
        }
        return board;
    }
};

#endif /* _88_find_min_step_h */
