//
//  299_get_hint.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/8.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _99_get_hint_h
#define _99_get_hint_h

class Solution {
public:
    string getHint(string secret, string guess) {
        int m[256] = {0}, bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) ++bulls;
            else {
                if (m[secret[i]]++ < 0) ++cows;
                if (m[guess[i]]-- > 0) ++ cows;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

#endif /* _99_get_hint_h */
