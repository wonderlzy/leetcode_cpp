//
//  109_sorted_list_bst.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/18.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _09_sorted_list_bst_h
#define _09_sorted_list_bst_h
#include "base_structure.h"

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        
        ListNode* fast = head, *slow = head;
        ListNode* last = slow;
        
        while(fast->next && fast->next->next ){
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        last->next = NULL;
        
        TreeNode* root = new TreeNode(slow->val);
        if(slow != head)
            root->left = sortedListToBST(head);
        
        root->right = sortedListToBST(fast);
        
        return root;
    }
};

#endif /* _09_sorted_list_bst_h */
