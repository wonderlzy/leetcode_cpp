//
//  76_min_window.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/5.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _6_min_window_h
#define _6_min_window_h

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || s.size() < t.size()) return "";
        const int ASCII_MAX = 256;
        int appeared_count[ASCII_MAX];
        int expected_count[ASCII_MAX];
        fill(appeared_count, appeared_count+ASCII_MAX, 0);
        fill(expected_count, expected_count+ASCII_MAX, 0);
        
        for(int i=0; i<t.size(); ++i)
            expected_count[t[i]]++;
        
        int minWidth = INT_MAX, min_start = 0;
        int wnd_start = 0;
        int appeared = 0;
        
        for(int wnd_end = 0; wnd_end < s.size(); ++wnd_end){
            if(expected_count[s[wnd_end]] > 0){
                appeared_count[s[wnd_end]]++;
                if(appeared_count[s[wnd_end]] <= expected_count[s[wnd_end]])
                    appeared++;
            }
            if(appeared == t.size()){
                while(appeared_count[s[wnd_start]] > expected_count[s[wnd_start]] || expected_count[s[wnd_start]] == 0){
                    --appeared_count[s[wnd_start]];
                    ++wnd_start;
                }
                if(minWidth > (wnd_end - wnd_start + 1)){
                    minWidth = wnd_end - wnd_start + 1;
                    min_start = wnd_start;
                }
            }
        }
        
        if(minWidth == INT_MAX) return "";
        else return s.substr(min_start, minWidth);
    }
};

#endif /* _6_min_window_h */
