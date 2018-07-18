//
//  107_level_order_bottom.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _07_level_order_bottom_h
#define _07_level_order_bottom_h

#include "base_structure.h"

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        traverse(root, result, 1);
        reverse(result.begin(), result.end());
        
        return result;
    }
    
    void traverse(TreeNode* root, vector<vector<int>>& result, int level){
        if(!root) return ;
        if(level > result.size())
            result.push_back(vector<int>());
        
        result[level-1].push_back(root->val);
        traverse(root->left, result, level+1);
        traverse(root->right, result, level+1);
    }
};

#endif /* _07_level_order_bottom_h */
