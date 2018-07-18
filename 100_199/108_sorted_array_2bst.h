//
//  108_sorted_array_2bst.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _08_sorted_array_2bst_h
#define _08_sorted_array_2bst_h

#include "base_structure.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return buildSearchTree(nums, 0, nums.size());
    }
    
private:
    TreeNode* buildSearchTree(vector<int>& nums, size_t left, size_t right){
        if(nums.empty() || left >= right) return NULL;
        
        size_t mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->val = nums[mid];
        root->left = buildSearchTree(nums, left, mid);
        root->right =  buildSearchTree(nums, mid+1, right);
        
        return root;
    }
};

#endif /* _08_sorted_array_2bst_h */
