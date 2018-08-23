//
//  725_split_list_2pair.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _25_split_list_2pair_h
#define _25_split_list_2pair_h

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k);
        int len = 0;
        for (ListNode *t = root; t; t = t->next) ++len;
        int avg = len / k, ext = len % k;
        for (int i = 0; i < k && root; ++i) {
            res[i] = root;
            for (int j = 1; j < avg + (i < ext); ++j) {
                root = root->next;
            }
            ListNode *t = root->next;
            root->next = NULL;
            root = t;
        }
        return res;
    }
};

#endif /* _25_split_list_2pair_h */
