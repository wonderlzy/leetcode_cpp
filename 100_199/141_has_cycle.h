//
//  141_has_cycle.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _41_has_cycle_h
#define _41_has_cycle_h
#include "base_structure.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        
        return false;
    }
};

#endif /* _41_has_cycle_h */
