//
//  85_maximal_rectangle.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/9.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _5_maximal_rectangle_h
#define _5_maximal_rectangle_h

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();
        vector<int> L(n, 0);
        vector<int> R(n, n);
        vector<int> H(n, 0);
        
        int ret = 0;
        for(int i=0; i<m; ++i){
            int left = 0, right = n;
            
            for(int j=0; j<n; ++j){
                if(matrix[i][j] == '1'){
                    ++H[j];
                    L[j] = max(L[j], left);
                } else {
                    L[j] = 0;
                    H[j] = 0;
                    R[j] = n;
                    left = j + 1;
                }
            }
            
            for(int j=n-1; j>=0; --j){
                if(matrix[i][j] == '1'){
                    R[j] = min(R[j], right);
                    ret = max(ret, H[j] * (R[j] - L[j]));
                } else {
                    right = j;
                }
            }
        }
        
        return ret;
        
        /*
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();
        
        vector<vector<int>> height(m, vector<int>(n, 0));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(matrix[i][j] == '0')
                    height[i][j] = 0;
                else
                    height[i][j] = (i==0) ? 1 : 1 + height[i-1][j];
            }
        }
        
        int maxArea = 0;
        for(int i=0; i<m; ++i){
            maxArea = max(maxArea, largestRectangle(height[i]));
        }
        
        return maxArea;
        */
    }
    
private:
    int largestRectangle(vector<int>& heights){
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

#endif /* _5_maximal_rectangle_h */
