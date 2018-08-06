//
//  275_h_index2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/7.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _75_h_index2_h
#define _75_h_index2_h

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size(), left = 0, right = len - 1;
        while (left <= right) {
            int mid = 0.5 * (left + right);
            if (citations[mid] == len - mid) return len - mid;
            else if (citations[mid] > len - mid) right = mid - 1;
            else left = mid + 1;
        }
        return len - left;
    }
};

#endif /* _75_h_index2_h */
