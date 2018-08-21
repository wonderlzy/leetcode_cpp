//
//  610_triangle_judgement.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _10_triangle_judgement_h
#define _10_triangle_judgement_h

SELECT
x,
y,
z,
CASE
WHEN x + y > z AND x + z > y AND y + z > x THEN 'Yes'
ELSE 'No'
END AS 'triangle'
FROM
triangle
;

#endif /* _10_triangle_judgement_h */
