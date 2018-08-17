//
//  411_fizz_buzz.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/15.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _11_fizz_buzz_h
#define _11_fizz_buzz_h

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) res.push_back("FizzBuzz");
            else if (i % 3 == 0) res.push_back("Fizz");
            else if (i % 5 == 0) res.push_back("Buzz");
            else res.push_back(to_string(i));
        }
        return res;
    }
};

#endif /* _11_fizz_buzz_h */
