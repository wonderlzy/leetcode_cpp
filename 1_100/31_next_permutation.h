//
//  31_next_permutation.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _1_next_permutation_h
#define _1_next_permutation_h

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len==0 || len == 1) return;
        auto id_iter = nums.rbegin();
        
        for(id_iter = next(id_iter); id_iter!=nums.rend(); ++id_iter){
            if(*id_iter < *(prev(id_iter)))
                break;
        }
        
        if(id_iter == nums.rend()){
            reverse(nums.begin(), nums.end());
            return ;
        }
        
        auto pos = find_if(nums.rbegin(), id_iter, bind2nd(greater<int>(), *id_iter));
        
        swap(*id_iter, *pos);
        reverse(nums.rbegin(), id_iter);
        
        return ;
    }
};

#endif /* _1_next_permutation_h */
