//
//  398_random_index.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/14.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _98_random_index_h
#define _98_random_index_h


class Solution {
public:
    Solution(vector<int> nums) : v(nums) {}
    
    int pick(int target) {
        int cnt = 0, res = -1;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != target) continue;
            ++cnt;
            if (rand() % cnt == 0) res = i;
        }
        return res;
    }
    
private:
    vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

#endif /* _98_random_index_h */
