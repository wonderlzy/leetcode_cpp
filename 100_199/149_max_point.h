//
//  149_max_point.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/30.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _49_max_point_h
#define _49_max_point_h


class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int res = 0;
        for(int i=0; i<points.size(); ++i){
            map<pair<int, int>, int> m;
            int duplicate = 1;
            for(int j=i+1; j<points.size(); ++j){
                if(points[i].x == points[j].x && points[i].y == points[j].y){
                    ++duplicate;
                    continue;
                }
                
                int dx = points[j].x-points[i].x;
                int dy = points[j].y-points[i].y;
                int d = gcd(dx, dy);
                
                ++m[{dx/d, dy/d}];
            }
            
            res = max(res, duplicate);
            for(auto it = m.begin(); it != m.end(); ++it){
                res = max(res, it->second + duplicate);
            }
        }
        
        return res;
    }
private:
    int gcd(int a, int b){
        return b==0 ? a : gcd(b, a % b);
    }
};

#endif /* _49_max_point_h */
