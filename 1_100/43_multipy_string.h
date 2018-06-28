//
//  43_multipy_string.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/26.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _3_multipy_string_h
#define _3_multipy_string_h

class Solution {
public:
    string multiply(string num1, string num2) {
        /*
        string result;
        int len1 = num1.size();
        int len2 = num2.size();
        
        if(len1 == 0 || len2 ==0) return result;
        if((len1 == 1 && num1[0] == '0') || (len2 == 1 && num2[0] == '0')) return "0";
        
        for(int i=len2-1; i>=0; --i){
            int save = 0;
            int add = 0;
            string local;
            for(int j=len1-1; j>=0; --j){
                save = ((num1[j]-'0') * (num2[i]-'0') + add) % 10 ;
                add = ((num1[j]-'0') * (num2[i]-'0') + add) / 10;
                local.insert(0, to_string(save));
            }
            
            if(add>0) local.insert(0, to_string(add));
            
            //update result
            if(result.empty()) {
                result = local;
                continue;
            }
            int m = result.size() - (len2-i);
            int n = local.size() - 1;
            add = 0;
            while(m>=0 || n>=0){
                int up = (m<0) ? 0 : result[m] - '0';
                int down = (n<0) ? 0 : local[n] - '0';
                if(m<0) result.insert(0, to_string((up+down+add)%10));
                else result[m] = (up+down+add)%10 + '0';
                add = (up+down+add) / 10;
                
                --m;
                --n;
            }
            if(add > 0) result.insert(0, to_string(add));
        }
        
        return result;
        */
        
        string res(num1.size()+num2.size(), '0');
        
        for(int i=num1.size()-1; i>=0; --i){
            for(int j=num2.size()-1; j>=0; --j){
                int a = i + j;
                int b = i + j + 1;
                
                int mul = (num1[i]-'0') * (num2[j]-'0') + (res[b] - '0');
                
                res[b] = mul % 10 + '0';
                res[a] += mul / 10;
            }
        }
        
        size_t start = res.find_first_not_of('0');
        return start==-1 ? "0" : res.substr(start);
    }
};

#endif /* _3_multipy_string_h */
