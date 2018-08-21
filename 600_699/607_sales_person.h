//
//  607_sales_person.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _07_sales_person_h
#define _07_sales_person_h

SELECT
s.name
FROM
salesperson s
WHERE
s.sales_id NOT IN (SELECT
                   o.sales_id
                   FROM
                   orders o
                   LEFT JOIN
                   company c ON o.com_id = c.com_id
                   WHERE
                   c.name = 'RED')
;

#endif /* _07_sales_person_h */
