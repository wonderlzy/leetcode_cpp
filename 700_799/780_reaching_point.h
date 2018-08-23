//
//  780_reaching_point.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _80_reaching_point_h
#define _80_reaching_point_h

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx > ty) {
                if (ty == sy) return (tx - sx) % ty == 0;
                tx %= ty;
            } else {
                if (tx == sx) return (ty - sy) % tx == 0;
                else ty %= tx;
            }
        }
        return tx == sx && ty == sy;
    }
};

#endif /* _80_reaching_point_h */
