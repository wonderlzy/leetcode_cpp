//
//  96_num_tree.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/10.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _6_num_tree_h
#define _6_num_tree_h

class Solution {
public:
    int numTrees(int n) {
        vector<int> fill(n+1, 0);
        fill[0] = 1;
        fill[1] = 1;
        
        for(int i=2; i<=n; ++i){
            for(int k=1; k<=i; ++k){
                fill[i] += fill[k-1]*fill[i-k];
            }
        }
        
        return fill[n];
    }
};

#endif /* _6_num_tree_h */
