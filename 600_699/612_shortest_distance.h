//
//  612_shortest_distance.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _12_shortest_distance_h
#define _12_shortest_distance_h

SELECT
ROUND(SQRT(MIN((POW(p1.x - p2.x, 2) + POW(p1.y - p2.y, 2)))),2) AS shortest
FROM
point_2d p1
JOIN
point_2d p2 ON (p1.x <= p2.x AND p1.y < p2.y)
OR (p1.x <= p2.x AND p1.y > p2.y)
OR (p1.x < p2.x AND p1.y = p2.y)
;

#endif /* _12_shortest_distance_h */
