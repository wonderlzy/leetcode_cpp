//
//  89_gray_code.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/9.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _9_gray_code_h
#define _9_gray_code_h

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return {0};
        vector<int> result({0,1});
        
        for(int i=2; i<=n; ++i){
            int cur = result.size() - 1;
            int add = 1 << (i-1);
            while(cur >= 0)
                result.push_back(result[cur--]+add);
        }
        
        return result;
    }
};

#endif /* _9_gray_code_h */
