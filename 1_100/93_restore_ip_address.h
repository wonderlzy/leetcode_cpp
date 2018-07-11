//
//  93_restore_ip_address.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/10.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _3_restore_ip_address_h
#define _3_restore_ip_address_h

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> path;
        if(s.empty()) return result;
        
        dfs(result, path, 0 , s);
        
        return result;
    }
    
private:
    void static dfs(vector<string>& result, vector<string>& path, int start, string & s){
        if(path.size() == 4 && start==s.size()){
            result.push_back(path[0]+'.'+path[1]+'.'+path[2]+'.'+path[3]);
            return ;
        }
        if((s.size()-start) < (4-path.size()))
           return ;
        if((s.size()-start) > (4-path.size())*3)
           return ;
        
        int num = 0;
        for(int i=start; i<start+3; ++i){
            num = num*10 + (s[i]-'0');
            if(num>255 || num<0) return ;
            
            path.push_back(s.substr(start, i-start+1));
            dfs(result, path, i+1, s);
            path.pop_back();
            
            if(num == 0) break; // important!
        }
    }
};

#endif /* _3_restore_ip_address_h */
