//
//  40_combination_sum2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/26.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _0_combination_sum2_h
#define _0_combination_sum2_h

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        if(candidates.empty()) return result;
        
        sort(candidates.begin(), candidates.end());
        dfs(candidates, path, result, target, 0);
        
        return result;
    }
    
    void dfs(vector<int>& nums, vector<int>& path, vector<vector<int>>& result, int gap, int start){
        if(gap == 0){
            result.push_back(path);
            return ;
        }
        
        int previous = -1;
        
        for(size_t i=start; i<nums.size(); ++i){
            if(nums[i] == previous) continue ;
            
            if(gap < nums[i])
                return ;
            
            previous = nums[i];
            
            path.push_back(nums[i]);
            dfs(nums, path, result, gap-nums[i], i+1);
            path.pop_back();
        }
    }
};

#endif /* _0_combination_sum2_h */
