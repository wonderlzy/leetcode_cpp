//
//  127_ladder_length.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/29.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _27_ladder_length_h
#define _27_ladder_length_h

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, int> m;
        queue<string> q;
        
        m[beginWord] = 1;
        q.push(beginWord);
        
        while(!q.empty()){
            string word = q.front();
            q.pop();
            
            for(int i=0; i<word.size(); ++i){
                string newWord = word;
                for(char ch='a'; ch <= 'z'; ++ch){
                    newWord[i] = ch;
                    if(dict.count(newWord) && newWord==endWord)
                        return m[word]+1;
                    if(dict.count(newWord) && !m.count(newWord)){
                        q.push(newWord);
                        m[newWord] = m[word]+1;
                    }
                }
            }
        }
        
        return 0;
    }
};

#endif /* _27_ladder_length_h */
