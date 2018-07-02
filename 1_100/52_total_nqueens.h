//
//  52_total_nqueens.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/28.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _2_total_nqueens_h
#define _2_total_nqueens_h

class Solution {
public:
    int totalNQueens(int n) {
        this->count = 0;
        vector<int> C(n, 0);
        dfs(C, 0);
        return this->count;
    }
    
    void dfs(vector<int>& C, int row){
        const int N = C.size();
        
        if(row == N){
            ++this->count;
            return ;
        }
        
        for(int j=0; j<N; ++j){
            bool ok = isValid(C, row, j);
            if(!ok) continue;
            
            C[row] = j;
            dfs(C, row+1);
        }
    }
    
    bool isValid(vector<int>& C, int row, int col){
        for(int j=0; j<row; ++j){
            if(C[j] == col) return false;
            
            if(abs(j-row) == abs(C[j]-col)) return false;
        }
        
        return true;
    }
    
private:
    int count ;
};

#endif /* _2_total_nqueens_h */
