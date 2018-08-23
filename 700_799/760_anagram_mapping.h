//
//  760_anagram_mapping.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _60_anagram_mapping_h
#define _60_anagram_mapping_h

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res;
        unordered_map<int, int> m;
        for (int i = 0; i < B.size(); ++i) m[B[i]] = i;
        for (int num : A) res.push_back(m[num]);
        return res;
    }
};

#endif /* _60_anagram_mapping_h */
