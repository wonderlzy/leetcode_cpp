//
//  735_are_setences_similarity.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _35_are_setences_similarity_h
#define _35_are_setences_similarity_h

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string, unordered_set<string>> m;
        for (auto pair : pairs) {
            m[pair.first].insert(pair.second);
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            if (!m[words1[i]].count(words2[i]) && !m[words2[i]].count(words1[i])) return false;
        }
        return true;
    }
};

#endif /* _35_are_setences_similarity_h */
