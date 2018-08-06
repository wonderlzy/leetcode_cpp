//
//  262_driver_and_client.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/6.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _62_driver_and_client_h
#define _62_driver_and_client_h

SELECT t.Request_at Day, ROUND(SUM(CASE WHEN t.Status LIKE 'cancelled%' THEN 1 ELSE 0 END)/COUNT(*), 2) 'Cancellation Rate'
FROM Trips t JOIN Users u ON t.Client_Id = u.Users_Id AND u.Banned = 'No'
WHERE t.Request_at BETWEEN '2013-10-01' AND '2013-10-03' GROUP BY t.Request_at;



#endif /* _62_driver_and_client_h */
