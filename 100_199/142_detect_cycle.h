//
//  142_detect_cycle.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018年 zhongyingli. All rights reserved.
//

#ifndef _42_detect_cycle_h
#define _42_detect_cycle_h

#include "base_structure.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        
        if(!fast || !fast->next)
            return NULL;
        
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast;
    }
};

#endif /* _42_detect_cycle_h */
