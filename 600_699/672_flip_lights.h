//
//  672_flip_lights.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _72_flip_lights_h
#define _72_flip_lights_h

class Solution {
public:
    int flipLights(int n, int m) {
        if (n == 0 || m == 0) return 1;
        if (n == 1) return 2;
        if (n == 2) return m == 1 ? 3 : 4;
        if (m == 1) return 4;
        return m == 2 ? 7 : 8;
    }
};

#endif /* _72_flip_lights_h */
