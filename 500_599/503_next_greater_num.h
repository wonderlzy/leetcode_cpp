//
//  504_next_greater_num.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _04_next_greater_num_h
#define _04_next_greater_num_h

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < 2 * n; ++i) {
            int num = nums[i % n];
            while (!st.empty() && nums[st.top()] < num) {
                res[st.top()] = num; st.pop();
            }
            if (i < n) st.push(i);
        }
        return res;
    }
};

#endif /* _04_next_greater_num_h */
