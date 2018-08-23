//
//  774_minmax_gas_dist.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _74_minmax_gas_dist_h
#define _74_minmax_gas_dist_h

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double left = 0, right = 1e8;
        while (right - left > 1e-6) {
            double mid = left + (right - left) / 2;
            int cnt = 0, n = stations.size();
            for (int i = 0; i < n - 1; ++i) {
                cnt += (stations[i + 1] - stations[i]) / mid;
            }
            if (cnt <= K) right = mid;
            else left = mid;
        }
        return left;
    }
};

#endif /* _74_minmax_gas_dist_h */
