//
//  382_list_random_node.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _82_list_random_node_h
#define _82_list_random_node_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = head->val, i = 2;
        ListNode *cur = head->next;
        while (cur) {
            int j = rand() % i;
            if (j == 0) res = cur->val;
            ++i;
            cur = cur->next;
        }
        return res;
    }
private:
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

#endif /* _82_list_random_node_h */
