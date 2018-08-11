//
//  306_is_additive_number.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _06_is_additive_number_h
#define _06_is_additive_number_h
class Solution {
public:
    bool isAdditiveNumber(string num) {
        if(num.size() < 3) return false;
        for(int i=1; i<num.size(); ++i){
            for(int j=i+1; j<num.size(); ++j){
                string str1 = num.substr(0, i);
                string str2 = num.substr(i, j-i);
                
                long long d1 = atoll(str1.c_str()), d2 = atoll(str2.c_str());
                if((str1.size()>1 && str1[0]=='0') || (str2.size()>1 && str2[0]=='0'))
                    continue;
                
                long long next = d1 + d2;
                string nexts = to_string(next);
                string now = str1+str2+nexts;
                
                while(now.size() < num.size()){
                    d1 = d2;
                    d2 = next;
                    next = d1+d2;
                    nexts = to_string(next);
                    now += nexts;
                }
                
                if(now == num) return true;
            }
        }
        
        return false;
    }
};

#endif /* _06_is_additive_number_h */
