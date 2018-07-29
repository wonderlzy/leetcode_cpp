//
//  125_is_palindrome.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/29.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _25_is_palindrome_h
#define _25_is_palindrome_h

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int left = 0, right = s.length()-1;
        
        while(left < right){
            if(!isalnum(s[left]))
                ++left;
            else if(!isalnum(s[right]))
                --right;
            else if((s[left]+32-'a') % 32 != (s[right]+32-'a') % 32)
                return false;
            else{
                ++left;
                --right;
            }
        }
        
        return true;
    }
};

#endif /* _25_is_palindrome_h */
