//
//  378_kth_smallest.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/13.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _78_kth_smallest_h
#define _78_kth_smallest_h

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        /*
        priority_queue<int> q;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[0].size(); ++j){
                q.emplace(matrix[i][j]);
                if(q.size()>k)
                    q.pop();
            }
        }
        return q.top();
        */
        
        if(matrix.empty() || matrix[0].empty())
            return -1;
        int left = matrix[0][0], right = matrix.back().back();
        while(left < right){
            int mid = left + (right - left) / 2;
            int cnt = search_less_equal(matrix, mid);
            if(cnt < k) left = mid + 1;
            else right = mid;
        }
        
        return left;
    }
    
    int search_less_equal(vector<vector<int>>& matrix, int target){
        int n = matrix.size(), i = n-1, j = 0, res = 0;
        
        while(i>=0 && j < n){
            if(matrix[i][j] <= target){
                res += i+1;
                ++j;
            } else
                --i;
        }
        return res;
    }
};

#endif /* _78_kth_smallest_h */
