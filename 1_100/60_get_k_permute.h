//
//  60_get_k_permute.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _0_get_k_permute_h
#define _0_get_k_permute_h

class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        string ch("123456789");
        vector<int> fill(n, 1);
        for(int i=1; i<n; ++i)
            fill[i] = fill[i-1]*i;
        --k;
        for(int i=n; i>=1; --i){
            int j = k / fill[i-1];
            result.push_back(ch[j]);
            k %= fill[i-1];
            ch.erase(j, 1);
        }
        
        return result;
        /*
        vector<int> nums;
        string result;
        nums.resize(n);
        for(int i=0; i<n; ++i)
            nums[i] = i+1;
        
        int count = 1;
        while(count++ < k)
            getNextPermute(nums);
        
        for(auto num : nums)
            result.push_back(num+'0');
        
        return result;
         */
    }
    
    void getNextPermute(vector<int>& nums){
        auto rbegin = nums.rbegin();
        for(rbegin = next(rbegin,1); rbegin != nums.rend(); ++rbegin){
            if(*rbegin < *prev(rbegin))
                break;
        }
        
        auto pos = find_if(nums.rbegin(), rbegin, bind2nd(greater<int>(), *rbegin));
        swap(*pos, *rbegin);
        reverse(nums.rbegin(), rbegin);
    }
};

#endif /* _0_get_k_permute_h */
