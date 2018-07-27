//
//  119_yh_getRow.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/27.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _19_yh_getRow_h
#define _19_yh_getRow_h

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> out;
        if(rowIndex <0)
            return out;
        
        out.assign(rowIndex + 1, 0);
        for(int i=0; i<=rowIndex; ++i){
            if(i == 0){
                out[0] = 1;
                continue;
            }
            
            for(int j=rowIndex; j>=1; --j){
                out[j] = out[j] + out[j-1];
            }
        }
        
        return out;
    }
};

#endif /* _19_yh_getRow_h */
