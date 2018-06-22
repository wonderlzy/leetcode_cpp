//
//  14_longest_comm_prefix.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _4_longest_comm_prefix_h
#define _4_longest_comm_prefix_h

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<=0) return "";
        
        const unsigned int nums = strs.size();
        unsigned int smallest_len = strs[0].length();
        string smallest_str = strs[0];
        string result;
        
        //get smallest string element
        for(vector<string>::iterator iter=strs.begin(); iter!=strs.end(); iter++){
            if((*iter).length()<smallest_len){
                smallest_len = (*iter).length();
                smallest_str = (*iter);
            }
        }
        
        for(int i=0; i<smallest_len; i++){
            bool is_profix = true;
            for(vector<string>::iterator iter=strs.begin(); iter!=strs.end(); iter++){
                if((*iter)[i] != smallest_str[i]){
                    is_profix = false;
                    break;
                }
            }
            if(!is_profix)
                break;
            
            result += smallest_str[i];
        }
        
        return result;
    }
};

#endif /* _4_longest_comm_prefix_h */
