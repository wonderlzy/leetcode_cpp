//
//  110_is_balanced.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/18.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _10_is_balanced_h
#define _10_is_balanced_h

#include "base_structure.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(getDepth(root->left)-getDepth(root->right)) > 1)
            return false;
        
        return  isBalanced(root->left) && isBalanced(root->right);
    }
    
private:
    int getDepth(TreeNode* root){
        if(!root) return 0;
        
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
};

#endif /* _10_is_balanced_h */
