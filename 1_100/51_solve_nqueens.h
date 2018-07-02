//
//  51_solve_nqueens.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/28.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _1_solve_nqueens_h
#define _1_solve_nqueens_h

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> C(n, -1);
        
        dfs(result, C, 0);
        return result;
    }
    
    void dfs(vector<vector<string>>& result, vector<int>& C, int row){
        const int N = C.size();
        if(row == N){
            vector<string> local;
            for(int i=0; i<N; ++i){
                string s(N, '.');
                for(int j=0; j<N; ++j){
                    if(C[i] == j)
                        s[j] = 'Q';
                }
                local.push_back(s);
            }
            
            result.push_back(local);
            return ;
        }
        
        for(int j=0; j<N; ++j){
            const bool ok = isValid(C, row, j);
            if(!ok) continue;
            
            C[row] = j;
            dfs(result, C, row+1);
            //C[row] = -1;
        }
    }
    
    bool isValid(vector<int>& C, int row, int col){
        for(int i=0; i<row; ++i){
            if(C[i] == col) return false;
            
            if(abs(i-row) == abs(C[i]-col)) return false;
        }
        
        return true;
    }
};

#endif /* _1_solve_nqueens_h */
