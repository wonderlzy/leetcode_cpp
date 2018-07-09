//
//  88_merge_sorted_array.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/9.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _8_merge_sorted_array_h
#define _8_merge_sorted_array_h

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0 || nums1.size() < (m+n)) return ;
        int i = m - 1, j = n - 1, k = nums1.size() - 1;
        while(i>=0 && j>=0 && k>=0)
            nums1[k--] = nums1[i]>=nums2[j] ? nums1[i--] : nums2[j--];
        
        while(j >= 0)
            nums1[k--] = nums2[j--];
        
        return ;
    }
};

#endif /* _8_merge_sorted_array_h */
