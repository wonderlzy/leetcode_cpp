//
//  800_similar_rgb.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _00_similar_rgb_h
#define _00_similar_rgb_h

class Solution {
public:
    string similarRGB(string color) {
        for (int i = 1; i < color.size(); i += 2) {
            int num = stoi(color.substr(i, 2), nullptr, 16);
            int idx = num / 17 + (num % 17 > 8 ? 1 : 0);
            color[i] = color[i + 1] = (idx > 9) ? (idx - 10 + 'a') : (idx + '0');
        }
        return color;
    }
};

#endif /* _00_similar_rgb_h */
