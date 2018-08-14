//
//  406_reconstruct_queue.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/14.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _06_reconstruct_queue_h
#define _06_reconstruct_queue_h

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        });
        
        vector<pair<int, int>> res;
        for(auto a : people)
            res.insert(res.begin()+a.second, a);
        
        return res;
    }
};

#endif /* _06_reconstruct_queue_h */
