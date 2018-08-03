//
//  223_compute_area.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/3.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _23_compute_area_h
#define _23_compute_area_h

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum = (C - A) * (D - B) + (H - F) * (G - E);
        if (E >= C || F >= D || B >= H || A >= G) return sum;
        return sum - ((min(G, C) - max(A, E)) * (min(D, H) - max(B, F)));
    }
};

#endif /* _23_compute_area_h */
