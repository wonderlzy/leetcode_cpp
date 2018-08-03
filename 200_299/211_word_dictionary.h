//
//  211_word_dictionary.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _11_word_dictionary_h
#define _11_word_dictionary_h

class WordDictionary {
    
public:
    class TrieNode {
    public:
        TrieNode *child[26];
        bool isWord;
        TrieNode() : isWord(false){
            memset(child, NULL, sizeof(child));
        }
    };
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for(auto ch : word){
            if(p->child[ch-'a'] == NULL)
                p->child[ch-'a'] = new TrieNode();
            p = p->child[ch-'a'];
        }
        
        p->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
        return searchWord(word, root, 0);
    }
    
    bool searchWord(string& word, TrieNode* p, int i){
        if(i==word.size())
            return p->isWord;
        if(word[i] == '.'){
            for(auto a : p->child){
                if(a && searchWord(word, a, i+1))
                    return true;
            }
            
            return false;
        } else {
            return p->child[word[i]-'a'] && searchWord(word, p->child[word[i]-'a'], i+1);
        }
    }
    
private:
    TrieNode* root;
};

#endif /* _11_word_dictionary_h */
