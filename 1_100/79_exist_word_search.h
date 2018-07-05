//
//  79_exist_word_search.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _9_exist_word_search_h
#define _9_exist_word_search_h

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        const int m = board.size();
        const int n = board[0].size();
        if(0 == n) return false;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                if(dfs(board, word, i, j, 0, visited))
                    return true;
        
        return false;
    }
    
private:
    static bool dfs(vector<vector<char>>& board, string& word, int x, int y, int step, vector<vector<bool>>& visited){
        if(step == word.size())
            return true;
            
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size())
            return false;
        
        if(visited[x][y] || board[x][y] != word[step])
            return false;
        
        visited[x][y] = true;
        bool ret =  dfs(board, word, x-1, y, step+1, visited) ||
        dfs(board, word, x, y+1, step+1, visited) ||
        dfs(board, word, x, y-1, step+1, visited) ||
        dfs(board, word, x+1, y, step+1, visited);
        visited[x][y] = false;
        
        return ret;
    }
};

#endif /* _9_exist_word_search_h */
