//
//  605_can_place_flower.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _05_can_place_flower_h
#define _05_can_place_flower_h

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (n == 0) return true;
            if (flowerbed[i] == 0) {
                int next = (i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1]);
                int pre = (i == 0 ? 0 : flowerbed[i - 1]);
                if (next + pre == 0) {
                    flowerbed[i] = 1;
                    --n;
                }
            }
        }
        return n <= 0;
    }
};

#endif /* _05_can_place_flower_h */
