//
//  168_convert_2title.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _68_convert_2title_h
#define _68_convert_2title_h

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n){
            res = char((n-1) % 26 + 'A') + res;
            n = (n-1) / 26;
        }
        
        return res;
    }
};

#endif /* _68_convert_2title_h */
