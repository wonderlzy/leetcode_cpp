//
//  619_biggest_single_numbers.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _19_biggest_single_numbers_h
#define _19_biggest_single_numbers_h

SELECT
MAX(num) AS num
FROM
(SELECT
 num
 FROM
 number
 GROUP BY num
 HAVING COUNT(num) = 1) AS t
;

#endif /* _19_biggest_single_numbers_h */
