//
//  222_count_nodes.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/3.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _22_count_nodes_h
#define _22_count_nodes_h

class Solution {
public:
    int countNodes(TreeNode* root) {
        int hLeft = 0, hRight = 0;
        TreeNode* pLeft = root, *pRight = root;
        while(pLeft){
            ++hLeft;
            pLeft = pLeft->left;
        }
        
        while(pRight){
            ++hRight;
            pRight = pRight->right;
        }
        
        if(hLeft == hRight) return pow(2, hLeft) - 1;
        
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

#endif /* _22_count_nodes_h */
