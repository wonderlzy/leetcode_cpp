//
//  62_unique_path.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _2_unique_path_h
#define _2_unique_path_h

class Solution {
public:
    typedef long long int64_t ;
    int uniquePaths(int m, int n) {
        return combination(m+n-2, min(m,n)-1);
        
        /*
        vector<int> fill(n, 0);
        fill[0] = 1;
        for(int i=0; i<m; ++i){
            for(int j=1; j<n; ++j){
                fill[j] = fill[j] + fill[j-1];
            }
        }
        
        return fill[n-1];
        */
    }
    
    static int64_t combination(int m, int n){
        if(n == 0) return 1;
        if(n == 1) return m;
        
        int64_t ret = factor(m, n);
        ret /= factor(n, n);
        return ret;
    }
    
    static int64_t factor(int base, int times){
        int64_t ret = base;
        while(--times > 0)
            ret *= (base-times);
        return ret;
    }
};

#endif /* _2_unique_path_h */
