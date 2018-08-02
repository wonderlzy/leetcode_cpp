//
//  206_reverse_list.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _06_reverse_list_h
#define _06_reverse_list_h

#include "base_structure.h"
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(-1);
        ListNode* pre = &dummy;
        ListNode* cur = head;
        
        while(head){
            cur = head->next;
            head->next = pre->next;
            pre->next = head;
            head = cur;
        }
        
        return dummy.next;
    }
};

#endif /* _06_reverse_list_h */
