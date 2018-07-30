//
//  134_can_complete_circuit.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/29.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _34_can_complete_circuit_h
#define _34_can_complete_circuit_h

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, sum = 0, start = 0;
        
        for(int i=0; i<gas.size(); ++i){
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            
            if(sum < 0){
                start = i+1;
                sum = 0;
            }
        }
        
        return (total >= 0) ? start : -1;
    }
};

#endif /* _34_can_complete_circuit_h */
