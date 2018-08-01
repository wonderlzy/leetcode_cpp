//
//  196_delete_duplicate_email.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _96_delete_duplicate_email_h
#define _96_delete_duplicate_email_h

DELETE FROM Person WHERE Id NOT IN
(SELECT Id FROM (SELECT MIN(Id) Id FROM Person GROUP BY Email) p);

DELETE p2 FROM Person p1 JOIN Person p2
ON p2.Email = p1.Email WHERE p2.Id > p1.Id;

DELETE p2 FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND p2.Id > p1.Id;

#endif /* _96_delete_duplicate_email_h */
