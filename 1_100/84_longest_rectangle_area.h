//
//  84_longest_rectangle_area.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/7.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _4_longest_rectangle_area_h
#define _4_longest_rectangle_area_h

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        
        int result = 0;
        for(int i=0; i<heights.size(); ){
            if(s.empty() || heights[i] > heights[s.top()])
                s.push(i++);
            
            else {
                int tmp = s.top();
                s.pop();
                result = max(result, heights[tmp] * (s.empty() ? i : (i - s.top() - 1)));
            }
        }
                
        return result;
    }
};

#endif /* _4_longest_rectangle_area_h */
