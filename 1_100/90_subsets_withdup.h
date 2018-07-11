//
//  90_subsets_withdup.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/9.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _0_subsets_withdup_h
#define _0_subsets_withdup_h

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty()) return {{}};
        vector<vector<int>> result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        
        dfs(result, path, nums, 0);
        
        return result;
    }
    
private:
    static void dfs(vector<vector<int>>& result, vector<int>& path, vector<int>&nums, int start){
        
        result.push_back(path);
        
        for(int i = start; i < nums.size(); ++i){
            if((i != start) && (nums[i] == nums[i-1]))
                continue;
            path.push_back(nums[i]);
            dfs(result, path, nums, i+1);
            path.pop_back();
        }
    }
};

#endif /* _0_subsets_withdup_h */
