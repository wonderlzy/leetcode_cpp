//
//  757_intersection_size2.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _57_intersection_size2_h
#define _57_intersection_size2_h

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        vector<int> v{-1, -1};
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });
        for (auto &interval : intervals) {
            int len = v.size();
            if (interval[0] <= v[len - 2]) continue;
            if (interval[0] > v.back()) v.push_back(interval[1] - 1);
            v.push_back(interval[1]);
        }
        return v.size() - 2;
    }
};

#endif /* _57_intersection_size2_h */
