//
//  457_circular_array_loop.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _57_circular_array_loop_h
#define _57_circular_array_loop_h

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            int cur = i;
            while (true) {
                visited[cur] = true;
                int next = (cur + nums[cur]) % n;
                if (next < 0) next += n;
                if (next == cur || nums[next] * nums[cur] < 0) break;
                if (m.count(next)) return true;
                m[cur] = next;
                cur = next;
            }
        }
        return false;
    }
};

#endif /* _57_circular_array_loop_h */
