//
//  138_copy_random_list.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _38_copy_random_list_h
#define _38_copy_random_list_h

#include "base_structure.h"

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        RandomListNode* cur = head;
        while(cur){
            RandomListNode* node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        
        cur = head;
        while(cur){
            if(cur->random)
                cur->next->random = cur->random->next;
            
            cur = cur->next->next;
        }
        
        cur = head;
        
        RandomListNode* res = head->next;
        while(cur){
            RandomListNode* tmp = cur->next;
            cur->next = tmp->next;
            if(tmp->next)
                tmp->next = tmp->next->next;
            cur = cur->next;
        }
        
        return res;
    }
};

#endif /* _38_copy_random_list_h */
