//
//  737_are_sentence_similarity2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _37_are_sentence_similarity2_h
#define _37_are_sentence_similarity2_h

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string, string> m;
        for (auto pair : pairs) {
            string x = getRoot(pair.first, m), y = getRoot(pair.second, m);
            if (x != y) m[x] = y;
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (getRoot(words1[i], m) != getRoot(words2[i], m)) return false;
        }
        return true;
    }
    string getRoot(string word, unordered_map<string, string>& m) {
        if (!m.count(word)) m[word] = word;
        return word == m[word] ? word : getRoot(m[word], m);
    }
};

#endif /* _37_are_sentence_similarity2_h */
