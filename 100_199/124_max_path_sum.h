//
//  124_max_path_sum.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/29.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _24_max_path_sum_h
#define _24_max_path_sum_h

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        getMaxPath(root, res);
        return res;
    }
    
private:
    int getMaxPath(TreeNode* root, int& res){
        if(!root) return 0;
        
        int left = max(getMaxPath(root->left, res), 0);
        int right = max(getMaxPath(root->right, res), 0);
        
        res = max(res, left+right+root->val);  // is the real return value
        
        return max(left, right) + root->val;
    }
};

#endif /* _24_max_path_sum_h */
