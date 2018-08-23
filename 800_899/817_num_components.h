//
//  817_num_components.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _17_num_components_h
#define _17_num_components_h

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> setG (G.begin(), G.end());
        int res = 0;
        while (head != NULL) {
            if (setG.count(head->val) && (head->next == NULL || !setG.count(head->next->val))) res++;
            head = head->next;
        }
        return res;
    }
};

#endif /* _17_num_components_h */
