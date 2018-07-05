//
//  71_simplify_path.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/4.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _1_simplify_path_h
#define _1_simplify_path_h

class Solution {
public:
    string simplifyPath(string path) {
        if(path.empty()) return path;
        vector<string> dirs;
        
        for(auto i=path.begin(); i!=path.end(); ){
            ++i;
            auto j = find(i, path.end(), '/');
            auto dir = string(i, j);
            
            if(!dir.empty() && dir!="."){
                if(dir == ".."){
                    if(!dirs.empty()) dirs.pop_back();
                } else
                    dirs.push_back(dir);
            }
            
            i = j;
        }
        
        string result ;
        if(dirs.empty()) return "/";
        else{
            for(auto dir : dirs){
                result.append("/");
                result.append(dir);
            }
        }
        
        return result;
    }
};

#endif /* _1_simplify_path_h */
