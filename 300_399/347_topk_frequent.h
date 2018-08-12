//
//  347_topk_frequent.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _47_topk_frequent_h
#define _47_topk_frequent_h

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> q;
        vector<int> res;
        
        for(auto num : nums)
            ++m[num];
        
        for(auto a : m)
            q.push(make_pair(a.second, a.first));
        
        for(int i=0; i<k; ++i){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};

#endif /* _47_topk_frequent_h */
