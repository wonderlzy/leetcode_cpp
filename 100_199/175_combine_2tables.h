//
//  175_combine_2tables.h
//  cpp_code
//
//  Created by zhongyingli on 2018/7/31.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _75_combine_2tables_h
#define _75_combine_2tables_h

SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person LEFT JOIN Address ON Person.PersonId = Address.PersonId;

SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person LEFT JOIN Address USING(PersonId);

SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person NATURAL LEFT JOIN Address;

#endif /* _75_combine_2tables_h */
