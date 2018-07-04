//
//  67_add_binary.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/3.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _7_add_binary_h
#define _7_add_binary_h

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty()) return b;
        if(b.empty()) return a;
        
        string result;
        int carry = 0;
        const size_t n = a.size() > b.size() ? a.size() : b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        for(int i=0; i<n; ++i){
            const int ai = i<a.size() ? a[i]-'0' : 0;
            const int bi = i<b.size() ? b[i]-'0' : 0;
            const int value = (ai+bi+carry) % 2;
            carry = (ai+bi+carry) / 2;
            result.insert(result.begin(), value + '0');
        }
        
        if(carry == 1) result.insert(result.begin(), '1');
        
        return result;
    }
};

#endif /* _7_add_binary_h */
