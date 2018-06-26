//
//  36_is_valid_suduku.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/25.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _6_is_valid_suduku_h
#define _6_is_valid_suduku_h

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() != 9) return false;
        if(board[0].size() != 9) return false;
        
        const int row = 9;
        const int col = 9;
        vector<bool> pos(row, false);
        
        //only once each row
        for(int i = 0; i<row; ++i){
            fill(begin(pos), end(pos), false);
            for(int j=0; j<col; ++j){
                if(board[i][j] < '1' || board[i][j] > '9')
                    continue;
                else{
                    if(pos[board[i][j]-'1'])
                        return false;
                    else pos[board[i][j]-'1'] = true;
                }
            }
            fill(begin(pos), end(pos), 0);
            for(int k=0; k<col; ++k){
                if(board[k][i] < '1' || board[k][i] > '9')
                    continue;
                else{
                    if(pos[board[k][i]-'1'])
                        return false;
                    else pos[board[k][i]-'1'] = true;
                }
            }
        }
        
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                fill(begin(pos), end(pos), false);
                
                for(int m=3*i; m<3*(i+1); ++m){
                    for( int n=3*j; n<3*(j+1); ++n){
                        if(board[m][n]<'1' || board[m][n]>'9')
                            continue;
                        else{
                            if(pos[board[m][n]-'1'])
                                return false;
                            else pos[board[m][n]-'1'] = true;
                        }
                    }
                }
            }
        }
        
        return true;
    }
        
};

#endif /* _6_is_valid_suduku_h */
