//
//  182_duplicate_email.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _82_duplicate_email_h
#define _82_duplicate_email_h

SELECT Email FROM Person GROUP BY Email
HAVING COUNT(*) > 1;

SELECT DISTINCT p1.Email FROM Person p1
JOIN Person p2 ON p1.Email = p2.Email
WHERE p1.Id <> p2.Id;


#endif /* _82_duplicate_email_h */
