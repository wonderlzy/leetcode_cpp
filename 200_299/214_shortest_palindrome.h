//
//  214_shortest_palindrome.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _14_shortest_palindrome_h
#define _14_shortest_palindrome_h

class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> next(t.size(), 0);
        
        for(int i=1; i<t.size(); ++i){
            int j = next[i-1];
            while(j>0 && t[j]!=t[i])
                j = next[j-1];
            next[i] = (j + (t[j] == t[i]));
        }
        
        return r.substr(0, s.size()-next.back()) + s;
        /*
        string t = s;
        reverse(t.begin(), t.end());
        const size_t n = s.size();
        int i = 0;
        
        for(i=n; i>=0; --i){
            if(s.substr(0, i) == t.substr(n-i))
                break;
        }
        
        return t.substr(0, n-i) + s;
        */
    }
};

#endif /* _14_shortest_palindrome_h */
