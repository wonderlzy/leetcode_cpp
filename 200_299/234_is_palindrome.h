//
//  234_is_palindrome.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _34_is_palindrome_h
#define _34_is_palindrome_h

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *last = slow->next, *pre = head;
        while(last->next){
            ListNode* tmp = last->next;
            last->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        
        while(slow->next){
            slow = slow->next;
            if(pre->val != slow->val)
                return false;
            pre = pre->next;
        }
        
        return true;
        
        /*
        if(!head || !head->next) return true;
        ListNode* slow = head, *fast = head;
        stack<int> s;
        s.push(head->val);
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            s.push(slow->val);
        }
        
        if(!fast->next) s.pop();
        while (slow->next) {
            slow = slow->next;
            int tmp = s.top();
            s.pop();
            if(tmp != slow->val)
                return false;
        }
        
        return true;
        */
    }
};

#endif /* _34_is_palindrome_h */
