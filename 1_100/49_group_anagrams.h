//
//  49_group_anagrams.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/28.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _9_group_anagrams_h
#define _9_group_anagrams_h

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> result;
        
        for(auto s : strs){
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        
        vector<string> local;
        for(auto iter = groups.begin(); iter !=groups.end(); ++iter){
            for(auto s : iter->second)
                local.push_back(s);
            result.push_back(local);
            local.resize(0);
        }
        
        return result;
    }
};

#endif /* _9_group_anagrams_h */
