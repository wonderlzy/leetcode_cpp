//
//  78_subset.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _8_subset_h
#define _8_subset_h

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()) return result;
        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(result, path, nums, 0);
        
        return result;
    }
    
private:
    static void dfs(vector<vector<int>>& result, vector<int>& path, vector<int>& nums,int step){
        if(step == nums.size()){
            result.push_back(path);
            return ;
        }
        dfs(result, path, nums, step+1);
        
        path.push_back(nums[step]);
        dfs(result, path, nums, step+1);
        path.pop_back();
    }
};

#endif /* _8_subset_h */
