//
//  648_replace_words.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _48_replace_words_h
#define _48_replace_words_h

class Solution {
public:
    class TrieNode {
    public:
        bool isWord;
        TrieNode *child[26];
        TrieNode(): isWord(false) {
            for (auto &a : child) a = NULL;
        }
    };
    
    string replaceWords(vector<string>& dict, string sentence) {
        string res = "", t = "";
        istringstream is(sentence);
        TrieNode *root = new TrieNode();
        for (string word : dict) {
            insert(root, word);
        }
        while (is >> t) {
            if (!res.empty()) res += " ";
            res += findPrefix(root, t);
        }
        return res;
    }
    
    void insert(TrieNode* node, string word) {
        for (char c : word) {
            if (!node->child[c - 'a']) node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
        }
        node->isWord = true;
    }
    
    string findPrefix(TrieNode* node, string word) {
        string cur = "";
        for (char c : word) {
            if (!node->child[c - 'a']) break;
            cur.push_back(c);
            node = node->child[c - 'a'];
            if (node->isWord) return cur;
        }
        return word;
    }
};

#endif /* _48_replace_words_h */
