//
//  208_trie_tree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _08_trie_tree_h
#define _08_trie_tree_h

class TrieNode{
public:
    TrieNode* next[26];
    bool isWord;
    
    TrieNode() : isWord(false){
        memset(next, NULL, sizeof(next));
    }
};

class Trie {
private:
    TrieNode* head;
public:
    /** Initialize your data structure here. */
    Trie() {
        head = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = head;
        for(int i=0; i<word.length(); ++i){
            if(cur->next[word[i]-'a'] == NULL)
                cur->next[word[i]-'a'] = new TrieNode();
        
            cur = cur->next[word[i]-'a'];
        }
        
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = head;
        for(auto ch : word){
            if(node->next[ch-'a'] == NULL)
                return false;
            node = node->next[ch-'a'];
        }
        
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = head;
        for(auto ch : prefix){
            if(node->next[ch-'a'] == NULL)
                return false;
            node = node->next[ch-'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

#endif /* _08_trie_tree_h */
