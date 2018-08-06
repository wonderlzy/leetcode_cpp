//
//  235_lowest_common_ancestor.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _35_lowest_common_ancestor_h
#define _35_lowest_common_ancestor_h

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || p==root || q==root) return root;
        if(root->val > max(p->val, q->val))
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val < min(p->val, q->val))
            return lowestCommonAncestor(root->right, p, q);
        else return root;
        
    }
};

#endif /* _35_lowest_common_ancestor_h */
