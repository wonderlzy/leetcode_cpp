//
//  68_full_justify.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/3.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _8_full_justify_h
#define _8_full_justify_h

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if(words.empty()) return words;
        vector<string> result;
        int cur_len = 0;
        auto begin_iter = words.begin(), end_iter = words.begin();
        for(auto iter = words.begin(); iter != words.end(); ++iter){
            int blank_num = iter-begin_iter;
            if(cur_len + (*iter).length() + blank_num > maxWidth){
                int interval = (blank_num<=1) ? maxWidth-cur_len : (maxWidth - cur_len) / (blank_num-1);
                int add = (blank_num<=1) ? 0 : (maxWidth - cur_len) % (blank_num-1);
                string tmp;
                while(begin_iter != iter){
                    tmp += *begin_iter;
                    if(next(begin_iter, 1) != iter)
                        tmp += string(interval, ' ');
                    if(add > 0){
                        tmp += " ";
                        --add;
                    }
                    ++begin_iter;
                }
                if(tmp.length() < maxWidth)
                    tmp += string(interval, ' ');
                result.push_back(tmp);
                
                cur_len = (*iter).length();
                begin_iter = iter;
                
            } else
                cur_len += (*iter).length();
        }
        
        string tmp;
        while(begin_iter != words.end()){
            tmp += *begin_iter;
            if(next(begin_iter, 1) != words.end())
                tmp += " ";
            ++begin_iter;
        }
        if(tmp.length() < maxWidth)
            tmp += string(maxWidth-tmp.length(), ' ');

        result.push_back(tmp);
        
        return result;
    }
};

#endif /* _8_full_justify_h */
