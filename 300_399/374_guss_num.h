//
//  374_guss_num.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _74_guss_num_h
#define _74_guss_num_h

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if(guess(n) == 0)
            return n;
        int left = 1, right = n;
        while(left < right){
            int mid = left + (right-left) / 2;
            int t = guess(mid);
            if(t == 0) return mid;
            else if(t == 1)
                left = mid;
            else right = mid;
        }
        
        return left;
    }
};

#endif /* _74_guss_num_h */
