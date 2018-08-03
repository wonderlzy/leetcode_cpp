//
//  216_combination_sum3.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _16_combination_sum3_h
#define _16_combination_sum3_h

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        combinationSum3DFS(k, n, 1, path, result);
        
        return result;
    }
    
    void combinationSum3DFS(int k, int n, int level, vector<int>&path ,vector<vector<int>>& result){
        if(n < 0) return ;
        if(n == 0 && path.size() == k)
            result.push_back(path);
        
        for(int i=level; i<=9; ++i){
            path.push_back(i);
            combinationSum3DFS(k, n-i, i+1, path, result);
            path.pop_back();
        }
    }
};

#endif /* _16_combination_sum3_h */
