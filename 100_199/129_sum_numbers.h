//
//  129_sum_numbers.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/29.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _29_sum_numbers_h
#define _29_sum_numbers_h

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbersDFS(root, 0);
    }
    
private:
    int sumNumbersDFS(TreeNode* root, int sum){
        if(!root) return 0;
        sum = 10*sum + root->val;
        if(!root->left && !root->right)
            return sum;
        return sumNumbersDFS(root->left, sum) + sumNumbersDFS(root->right, sum);
    }
};

#endif /* _29_sum_numbers_h */
