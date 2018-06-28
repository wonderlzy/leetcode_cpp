//
//  46_permute.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/27.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _6_permute_h
#define _6_permute_h

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        if(nums.empty()) return result;
        
        dfs(nums, result, path);
        
        return result;
    }
    
    void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& path){
        if(path.size() == nums.size()){
            result.push_back(path);
            return ;
        }
        
        for(auto data : nums){
            auto pos = find(path.begin(), path.end(), data);
            if(pos == path.end()){
                path.push_back(data);
                dfs(nums, result, path);
                path.pop_back();
            }
        }
    }
};

#endif /* _6_permute_h */
