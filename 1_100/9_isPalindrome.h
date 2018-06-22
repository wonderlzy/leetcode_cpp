//
//  9_isPalindrome.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/12.
//  Copyright © 2018年 zhongyingli. All rights reserved.
//

#ifndef __isPalindrome_h
#define __isPalindrome_h
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        
        int tmp = x;
        int reverse = 0;
        while(tmp){
            reverse = reverse * 10 + tmp%10;
            tmp /= 10;
        }
        
        return reverse == x;
    }
};

#endif /* __isPalindrome_h */
