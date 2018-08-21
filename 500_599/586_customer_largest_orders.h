//
//  586_customer_largest_orders.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _86_customer_largest_orders_h
#define _86_customer_largest_orders_h

SELECT
customer_number
FROM
orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1
;

#endif /* _86_customer_largest_orders_h */
