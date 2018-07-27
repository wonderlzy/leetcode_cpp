//
//  113_path_sum2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/19.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _13_path_sum2_h
#define _13_path_sum2_h

#include "base_structure.h"
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        if(!root) return result;
        
        findPath(root, sum, result, path);
        
        return result;
    }
private:
    void findPath(TreeNode* root, int sum, vector<vector<int>>& result, vector<int>& path){
        if(!root) return;
        
        path.push_back(root->val);
        if(!root->left && !root->right && root->val==sum)
            result.push_back(path);
        
        
        findPath(root->left, sum-root->val, result, path);
        findPath(root->right, sum-root->val, result, path);
        path.pop_back();
    }
};

#endif /* _13_path_sum2_h */
