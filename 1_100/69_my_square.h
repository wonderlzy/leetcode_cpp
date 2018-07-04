//
//  69_my_square.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/4.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _9_my_square_h
#define _9_my_square_h

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int left = 1, right = x/2;
        int last_mid = 0;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(x/mid > mid){
                left = mid + 1;
                last_mid = mid;
            } else if(x/mid < mid){
                right = mid - 1;
            }
            else return mid;
        }
        
        return last_mid;
    }
};

#endif /* _9_my_square_h */
