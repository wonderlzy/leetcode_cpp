//
//  61_rotate_right.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _1_rotate_right_h
#define _1_rotate_right_h


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k<=0) return head;
        int len = 1;
        ListNode* oldEnd = head;
        while(oldEnd->next != NULL){
            ++len;
            oldEnd = oldEnd->next;
        }
        k = k % len;
        if(k == 0) return head;
        
        ListNode* newEnd = head;
        for(int i=1; i<len-k; ++i)
            newEnd = newEnd->next;
        
        ListNode* newHead = newEnd->next;
        newEnd->next = NULL;
        oldEnd->next = head;
        
        return newHead;
    }
};

#endif /* _1_rotate_right_h */
