//
//  202_is_happy.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _02_is_happy_h
#define _02_is_happy_h

class Solution {
public:
    bool isHappy(int n) {
        if(n <= 0) return false;
        if(1 == n) return true;
        set<int> s;
        
        while(n != 1 && !s.count(n)){
            s.insert(n);
            if(n < 10)
                n = n*n;
            else{
                int sum = 0;
                while (n >= 10) {
                    sum += pow(n%10, 2) ;
                    n /= 10;
                }
                sum += pow(n, 2);
                
                n = sum;
            }
        }
        
        return n==1 ? true : false;
    }
};

#endif /* _02_is_happy_h */
