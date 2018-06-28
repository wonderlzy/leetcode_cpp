//
//  42_trap_water.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/26.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _2_trap_water_h
#define _2_trap_water_h

class Solution {
public:
    int trap(vector<int>& height) {
        /*
        const int len = height.size();
        if(len<=2) return 0;
        int water = 0;
        stack<int> s;
        
        for(int i=0; i<len; ++i){
            int high = 0;
            
            while(!s.empty()){
                int bar = height[s.top()];
                int pos = s.top();
                water += (min(bar, height[i]) - high)*(i-pos-1);
                high = bar;
                
                if(height[i]<bar)
                    break;
                else
                    s.pop();
            }
            
            s.push(i);
        }
        
        
        return water;
        */
        const int len = height.size();
        if(len<=2) return 0;
        int water = 0, max = 0;
        for(int i=0; i<len; ++i){
            if(height[i]>height[max])
                max = i;
        }
        
        for(int m=0, peek=0; m<max; ++m){
            if(height[m] > peek)
                peek = height[m];
            else
                water += peek - height[m];
        }
        
        for(int n=len-1, peek=0; n>max; --n){
            if(height[n] > peek)
                peek = height[n];
            else
                water += peek - height[n];
        }
        
        return water;
    }
};

#endif /* _2_trap_water_h */
