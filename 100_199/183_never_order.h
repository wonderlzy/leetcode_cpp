//
//  183_never_order.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _83_never_order_h
#define _83_never_order_h

SELECT Name AS Customers FROM Customers
WHERE Id NOT IN (SELECT CustomerId FROM Orders);


SELECT Name AS Customers FROM Customers
LEFT JOIN Orders ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL;

#endif /* _83_never_order_h */
