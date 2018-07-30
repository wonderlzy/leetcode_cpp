//
//  131_partition.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/29.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _31_partition_h
#define _31_partition_h

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        
        partitaionDFS(result, path, 0, s);
        return result;
    }
    
private:
    void partitaionDFS(vector<vector<string>>& result, vector<string>& path, int start, string& s){
        
        if(start == s.size()){
            result.push_back(path);
            return ;
        }
        
        for(int i=start; i<s.size(); ++i){
            if(isPalindrom(s, start, i)){
                path.push_back(s.substr(start, i-start+1));
                partitaionDFS(result, path, i+1, s);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrom(string s, int start, int end){
        while(start < end){
            if(s[start] != s[end])
                return false;
            
            ++start;
            --end;
        }
        
        return true;
    }
};

#endif /* _31_partition_h */
