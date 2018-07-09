//
//  86_partition_list.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/9.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _6_partition_list_h
#define _6_partition_list_h


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return head;
        
        ListNode result(-1);
        result.next = head;
        ListNode* valid = &result;
        ListNode* visit = &result;
        
        while(visit->next != NULL){
            ListNode* curVisit = visit;
            visit = visit->next;
            
            if(visit->val < x){
                curVisit->next = visit->next;
                
                ListNode* validNext = valid->next;
                valid->next = visit;
                visit->next = validNext;
                valid = visit;
            }
            
        }
        
        return result.next;
    }
};

#endif /* _6_partition_list_h */
