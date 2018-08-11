//
//  307_num_array2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/11.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _07_num_array2_h
#define _07_num_array2_h

class NumArray {
public:
    NumArray(vector<int> nums) {
        num.resize(nums.size()+1);
        bit.resize(nums.size()+1);
        for(int i=0; i<nums.size(); ++i)
            update(i, nums[i]);
    }
    
    void update(int i, int val) {
        int diff = val - num[i+1];
        for(int j=i+1; j<num.size(); j+=(j&-j))
            bit[j] += diff;
        
        num[i+1] = val;
    }
    
    int sumRange(int i, int j) {
        return getSum(j+1) - getSum(i) ;
    }
    
    int getSum(int i){
        int res = 0;
        for(int j = i; j>0; j-=(j&-j))
            res += bit[j];
        
        return res;
    }
private:
    vector<int> num;
    vector<int> bit;
};

#endif /* _07_num_array2_h */
