//
//  23_merge_ksorted_list.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/19.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _3_merge_ksorted_list_h
#define _3_merge_ksorted_list_h


 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
/*class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())  return nullptr;
        
        ListNode *p = lists[0];
        for(int i=1; i<lists.size(); ++i){
            p = mergeTwoLists(p, lists[i]);
        }
        
        return p;
    }
    
    ListNode *mergeTwoLists(ListNode *left, ListNode *right){
        ListNode dummy(-1);
        for(ListNode *p = &dummy; left!=nullptr || right!=nullptr; p = p->next){
            int val1 = (left==nullptr) ? INT_MAX : left->val;
            int val2 = (right==nullptr) ? INT_MAX : right->val;
            
            if(val1 <= val2){
                p->next = left;
                left = left->next;
            }
            else{
                p->next = right;
                right = right->next;
            }
        }
        
        return dummy.next;
    }
    
};
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        if(lists.size() == 1) return lists[0];
        if(lists.size() == 2) return mergeTwoLists(lists[0], lists[1]);
        
        int middle = lists.size() / 2;
        vector<ListNode*> left(lists.begin(), next(lists.begin(), middle));
        vector<ListNode*> right(next(lists.begin(), middle), lists.end());

        return mergeTwoLists(mergeKLists(left), mergeKLists(right));
    }
    
    ListNode* mergeTwoLists(ListNode *left, ListNode *right){
        ListNode head(-1);
        for(ListNode *p = &head; left!=nullptr || right!=nullptr; p=p->next){
            int val1 = (left==nullptr) ? INT_MAX : left->val;
            int val2 = (right==nullptr) ? INT_MAX : right->val;
            if(val1 <= val2){
                p->next = left;
                left = left->next;
            } else{
                p->next = right;
                right = right->next;
            }
        }
        
        return head.next;
    }
};

#endif /* _3_merge_ksorted_list_h */
