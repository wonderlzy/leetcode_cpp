//
//  492_construct_rectangle.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/20.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _92_construct_rectangle_h
#define _92_construct_rectangle_h

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int r = sqrt(area);
        while (area % r != 0) --r;
        return {area / r, r};
    }
};

#endif /* _92_construct_rectangle_h */
