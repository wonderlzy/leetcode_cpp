//
//  147_insert_sort_list.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _47_insert_sort_list_h
#define _47_insert_sort_list_h

#include "base_structure.h"
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        
        while(head){
            ListNode* t = head->next;
            cur = dummy;
            
            while(cur->next && cur->next->val <= head->val)
                cur = cur->next;
            
            head->next = cur->next;
            cur->next = head;
            head = t;
        }
        
        return dummy->next;
    }
};

#endif /* _47_insert_sort_list_h */
