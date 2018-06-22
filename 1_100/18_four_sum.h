//
//  18_four_sum.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/14.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _8_four_sum_h
#define _8_four_sum_h

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        
        unordered_multimap<int, pair<int, int>> cache;
        for(int i=0; i<nums.size(); ++i)
            for(int j=i+1; j<nums.size(); ++j)
                cache.insert(make_pair(nums[i]+nums[j], make_pair(i, j)));
        
        for(auto m=cache.begin(); m!=cache.end(); ++m){
            int remain = target - m->first;
            auto range = cache.equal_range(remain);
            
            for(auto n=range.first; n!=range.second; ++n){
                auto a = m->second.first;
                auto b = m->second.second;
                auto c = n->second.first;
                auto d = n->second.second;
                
                if(a!=c && a!=d && b!=c && b!=d){
                    vector<int> vec = {nums[a], nums[b], nums[c], nums[d]};
                    sort(vec.begin(), vec.end());
                    result.push_back(vec);
                }
            }
        }
        
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        
        return result;
    }
};

#endif /* _8_four_sum_h */
