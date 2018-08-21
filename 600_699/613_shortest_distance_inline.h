//
//  613_shortest_distance_inline.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _13_shortest_distance_inline_h
#define _13_shortest_distance_inline_h

SELECT
MIN(ABS(p1.x - p2.x)) AS shortest
FROM
point p1
JOIN
point p2 ON p1.x != p2.x
;

#endif /* _13_shortest_distance_inline_h */
