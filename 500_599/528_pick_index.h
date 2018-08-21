//
//  528_pick_index.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _28_pick_index_h
#define _28_pick_index_h

class Solution {
public:
    vector<int> s;
    Solution(vector<int> w) {
        for (int i : w) s.push_back(s.empty() ? i : (i + s.back()));
    }
    
    int pickIndex() {
        int m = s.back();
        int r = rand() % m;
        auto it = upper_bound(s.begin(), s.end(), r);
        return it - s.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

#endif /* _28_pick_index_h */
