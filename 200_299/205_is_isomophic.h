//
//  205_is_isomophic.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _05_is_isomophic_h
#define _05_is_isomophic_h

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const size_t m = s.size();
        const size_t n = t.size();
        if(m != n) return false;
        
        vector<int> sp(255, 0);
        vector<int> tp(255, 0);
        
        for(int i=0; i<m; ++i){
            if(sp[s[i]] != tp[t[i]])
                return false;
            sp[s[i]] = i+1;
            tp[t[i]] = i+1;
        }
        
        return true;
    }
};

#endif /* _05_is_isomophic_h */
