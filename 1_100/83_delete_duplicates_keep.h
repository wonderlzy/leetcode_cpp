//
//  83_delete_duplicates.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/7.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _3_delete_duplicates_h
#define _3_delete_duplicates_h

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        for(ListNode* pre=head, *cur=head->next; cur!=NULL; cur=pre->next){
            if(cur->val == pre->val)
                pre->next = cur->next;
            else
                pre = cur;
        }
        
        return head;
    }
};

#endif /* _3_delete_duplicates_h */
