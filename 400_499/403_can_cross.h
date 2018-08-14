//
//  403_can_cross.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/14.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _03_can_cross_h
#define _03_can_cross_h

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> m;
        return helper(stones, 0, 0, m);
    }
    
    bool helper(vector<int>& stones, int pos, int jump, unordered_map<int, bool>& m){
        int n = stones.size(), key = pos | jump << 11;
        if(pos >= n-1) return true;
        if(m.count(key)) return m[key];
        
        for(int i=pos+1; i<n; ++i){
            int dis = stones[i] - stones[pos];
            if(dis < jump-1)
                continue;
            if(dis > jump+1)
                return m[key]=false;
            if(helper(stones, i, dis, m))
                return m[key]=true;
        }
        
        return m[key] = false;
    }
};

#endif /* _03_can_cross_h */
