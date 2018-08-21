//
//  616_exchange_seats.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _16_exchange_seats_h
#define _16_exchange_seats_h

SELECT
s1.id, COALESCE(s2.student, s1.student) AS student
FROM
seat s1
LEFT JOIN
seat s2 ON ((s1.id + 1) ^ 1) - 1 = s2.id
ORDER BY s1.id;

#endif /* _16_exchange_seats_h */
