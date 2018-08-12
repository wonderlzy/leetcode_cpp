//
//  324_wiggle_sort.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _24_wiggle_sort_h
#define _24_wiggle_sort_hclass Solution {

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
        size_t len = nums.size(), low = 0, hign = len - 1, mid = nums[len/2], i = 0;
        auto index = [=](int pos){
            return (1+pos*2)%(len | 1);
        };
        
        while(i<=hign){
            if(nums[index(i)] > mid)
                swap(nums[index(i++)], nums[index(low++)]);
            else if(nums[index(i)]<mid)
                swap(nums[index(i)], nums[index(hign--)]);
            else
                ++i;
        }
        
        /*
        vector<int> tmp = nums;
        size_t n = nums.size(), k = (n+1) / 2, j = n;
        sort(tmp.begin(), tmp.end());
        
        for(int i=0; i<n; ++i){
            nums[i] = i & 1 ? tmp[--j] : tmp[--k];
        }
        */
    }
};

#endif /* _24_wiggle_sort_h */
