//
//  331_is_valid_serialization.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _31_is_valid_serialization_h
#define _31_is_valid_serialization_h

class Solution {
public:
    bool isValidSerialization(string preorder) {
        istringstream in(preorder);
        string t= "";
        vector<string> v;
        int cnt = 0;
        
        while(getline(in, t, ','))
            v.push_back(t);
        
        for(int i=0; i<v.size()-1; ++i){
            if(v[i] == "#"){
                if(cnt == 0) return false;
                --cnt;
            } else
                ++cnt;
        }
        
        return cnt==0 && v.back()=="#";
    }
};

#endif /* _31_is_valid_serialization_h */
