//
//  212_find_words.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _12_find_words_h
#define _12_find_words_h

class Solution {
public:
    struct TrieNode{
        TrieNode* child[26];
        string str;
        TrieNode() : str(""){
            memset(child, NULL, sizeof(child));
        }
    };
    
    struct Trie {
    public:
        Trie(){
            root = new TrieNode();
        }
        
        void insert(string word){
            TrieNode* p = root;
            for(auto ch : word){
                if(!p->child[ch-'a'])
                    p->child[ch-'a'] = new TrieNode();
                
                p = p->child[ch-'a'];
            }
            
            p->str = word;
        }
        
    public:
        TrieNode* root;
    };
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(board.empty() || words.empty() || board[0].empty())
            return res;
        
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        Trie T;
        
        for(auto word : words)  T.insert(word);
        
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(T.root->child[board[i][j]-'a']){
                    search(board, T.root->child[board[i][j]-'a'], i, j, visit, res);
                }
            }
        }
        
        return res;
    }
    
    void search(vector<vector<char>>& board, TrieNode* p, int i, int j, vector<vector<bool>>& visit, vector<string>& res){
        if(!p->str.empty()){
            res.push_back(p->str);
            p->str.clear();
        }
        
        int d[4][2] = {{0,-1}, {0, 1}, {-1, 0}, {1, 0}};
        visit[i][j] = true;
        
        for(auto a : d){
            int nx = i+a[0], ny = j+a[1];
            if(nx>=0 && nx<board.size() && ny>=0 &&ny<board[0].size() && !visit[nx][ny] && p->child[board[nx][ny]-'a'])
                search(board, p->child[board[nx][ny]-'a'], nx, ny, visit, res);
        }
        
        visit[i][j] = false;
    }
};

#endif /* _12_find_words_h */
