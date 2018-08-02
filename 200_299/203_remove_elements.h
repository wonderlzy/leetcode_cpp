//
//  203_remove_elements.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _03_remove_elements_h
#define _03_remove_elements_h

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* res = new ListNode(-1);
        ListNode* cur = head, *pre = res;
        
        while(cur){
            if(cur->val == val)
                cur = cur->next;
            else{
                pre->next = cur;
                cur = cur->next;
                pre = pre->next;
                pre->next = NULL;
            }
            
        }
        
        return res->next;
    }
};

#endif /* _03_remove_elements_h */
