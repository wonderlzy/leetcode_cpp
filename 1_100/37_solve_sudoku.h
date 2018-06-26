//
//  37_solve_sudoku.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/26.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _7_solve_sudoku_h
#define _7_solve_sudoku_h

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        const int len = 9;
        if(board.size() != len) return ;
        if(board[0].size() != len) return;
        isSudoku(board);
    }
    
    bool isSudoku(vector<vector<char>>& board){
        const int len = 9;
        
        for(int i=0; i<len; ++i){
            for(int j=0; j<len; ++j){
                if(board[i][j] == '.'){
                    for(int k=0; k<9; ++k){
                        board[i][j] = '1' + k;
                        if(isValid(board, i, j) && isSudoku(board))
                            return true;
                        board[i][j] = '.';
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int x, int y){
        for(int i=0; i<9; ++i){ // check row
            if(i!=y && board[x][i]==board[x][y])
                return false;
        }
        
        for(int j=0; j<9; ++j){ // check col
            if(j!=x && board[j][y]==board[x][y])
                return false;
        }
        
        for(int m=3*(x/3); m<3*(x/3+1); ++m){
            for(int n=3*(y/3); n<3*(y/3+1); ++n){
                if((m!=x || n!=y) && (board[m][n]==board[x][y]))
                    return false;
            }
        }
        
        return true;
    }
};

#endif /* _7_solve_sudoku_h */
