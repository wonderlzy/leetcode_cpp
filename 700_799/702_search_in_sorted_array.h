//
//  702_search_in_sorted_array.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _02_search_in_sorted_array_h
#define _02_search_in_sorted_array_h

// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0, right = 19999;
        while (left <= right) {
            auto mid = left + (right-left) / 2;
            auto response = reader.get(mid);
            if (response > target) {
                right = mid - 1;
            } else if (response < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

#endif /* _02_search_in_sorted_array_h */
