//
//  676_magic_dictionary.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _76_magic_dictionary_h
#define _76_magic_dictionary_h

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {}
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string word : dict) s.insert(word);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (int i = 0; i < word.size(); ++i) {
            char t = word[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == t) continue;
                word[i] = c;
                if (s.count(word)) return true;
            }
            word[i] = t;
        }
        return false;
    }
    
private:
    unordered_set<string> s;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

#endif /* _76_magic_dictionary_h */
