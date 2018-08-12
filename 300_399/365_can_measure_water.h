//
//  365_can_measure_water.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _65_can_measure_water_h
#define _65_can_measure_water_h

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        
        return z==0 || (x+y>=z && z%gcd(x, y)==0);
    }
    
    int gcd(int x, int y){
        return y==0 ? x : gcd(y, x%y);
    }
};

#endif /* _65_can_measure_water_h */
