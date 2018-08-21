//
//  559_max_depth.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _59_max_depth_h
#define _59_max_depth_h

#include "../base_structure.h"
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        
        int max_depth = 0;
        for (auto child : root->children) {
            max_depth = std::max(max_depth, maxDepth(child));
        }
        
        return 1 + max_depth;
    }
};

#endif /* _59_max_depth_h */
