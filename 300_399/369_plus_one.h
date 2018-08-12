//
//  369_plus_one.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _69_plus_one_h
#define _69_plus_one_h

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *cur = head, *right = NULL;
        while (cur) {
            if (cur->val != 9) right = cur;
            cur = cur->next;
        }
        if (!right) {
            right = new ListNode(0);
            right->next = head;
            head = right;
        }
        ++right->val;
        cur = right->next;
        while (cur) {
            cur->val = 0;
            cur = cur->next;
        }
        return head;
        /*
         if (!head) return head;
         ListNode *rev_head = reverse(head), *cur = rev_head, *pre = cur;
         int carry = 1;
         while (cur) {
         pre = cur;
         int t = cur->val + carry;
         cur->val = t % 10;
         carry = t / 10;
         if (carry == 0) break;
         cur = cur->next;
         }
         if (carry) pre->next = new ListNode(1);
         return reverse(rev_head);
         */
    }
    
    ListNode* reverse(ListNode *head) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1), *cur = head;
        dummy->next = head;
        while (cur->next) {
            ListNode *t = cur->next;
            cur->next = t->next;
            t->next = dummy->next;
            dummy->next = t;
        }
        return dummy->next;
    }
};

#endif /* _69_plus_one_h */
