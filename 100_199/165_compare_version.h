//
//  165_compare_version.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _65_compare_version_h
#define _65_compare_version_h

class Solution {
public:
    int compareVersion(string version1, string version2) {
        const size_t n1 = version1.size();
        const size_t n2 = version2.size();
        
        int i = 0, j = 0, d1 = 0, d2 = 0;
        string v1, v2;
        
        while(i < n1 || j < n2){
            while( i < n1 && version1[i] != '.')
                v1.push_back(version1[i++]);
            d1 = atoi(v1.c_str());
            
            while( j < n2 && version2[j] != '.')
                v2.push_back(version2[j++]);
            d2 = atoi(v2.c_str());
            
            if(d1 > d2) return 1;
            else if(d1 < d2) return -1;
            
            v1.clear();
            v2.clear();
            ++i;
            ++j;
        }
        
        return 0;
    }
};

#endif /* _65_compare_version_h */
