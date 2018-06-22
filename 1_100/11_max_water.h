//
//  11_max_water.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/12.
//  Copyright © 2018年 zhongyingli. All rights reserved.
//

#ifndef _1_max_water_h
#define _1_max_water_h

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int result = 0;
        
        while(start < end){
            int area = min(height[start], height[end]) * (end - start);
            result = max(result, area);
            if(height[start]<=height[end])
                start++;
            else end--;
        }
    
        return result;
    }
};

#endif /* _1_max_water_h */

/*
 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。画 n 条垂直线，使得垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 注意：你不能倾斜容器，n 至少是2。
*/
