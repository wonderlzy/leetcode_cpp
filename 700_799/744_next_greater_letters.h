//
//  744_next_greater_letters.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _44_next_greater_letters_h
#define _44_next_greater_letters_h

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target >= letters.back()) return letters[0];
        int n = letters.size(), left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target) left = mid + 1;
            else right = mid;
        }
        return letters[right];
    }
};

#endif /* _44_next_greater_letters_h */
