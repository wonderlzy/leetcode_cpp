//
//  328_odd_even_list.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _28_odd_even_list_h
#define _28_odd_even_list_h

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* odd = head, *even = head->next, *even_head = even;
        
        while(even && even->next){
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        
        odd->next = even_head;
        
        return head;
    }
};

#endif /* _28_odd_even_list_h */
