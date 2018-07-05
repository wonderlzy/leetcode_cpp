//
//  77_combine.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _7_combine_h
#define _7_combine_h

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(k > n) return result;
        
        vector<int> path;
        dfs(result, path, n, k, 1);
        
        return result;
    }
    
private:
    static void dfs(vector<vector<int>>& result, vector<int>& path, int n, int k, int start){
        if(path.size() == k){
            result.push_back(path);
            return ;
        }
        else {
            for(int i=start; i<=n; ++i){
                path.push_back(i);
                dfs(result, path, n, k, i+1);
                path.pop_back();
            }
        }
    }
};

#endif /* _7_combine_h */
