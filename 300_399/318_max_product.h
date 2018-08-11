//
//  318_max_product.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/12.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _18_max_product_h
#define _18_max_product_h

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<int> mask(words.size(), 0);
        
        for(int i=0; i<words.size(); ++i){
            for(auto word : words[i]){
                mask[i] |= 1 << (word - 'a');
            }
            
            for(int j=0; j<i; ++j){
                if(!(mask[i]&mask[j]))
                    res = max(res, int(words[i].size() * words[j].size()));
            }
        }
        
        return res;
    }
};

#endif /* _18_max_product_h */
