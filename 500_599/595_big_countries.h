//
//  595_big_countries.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _95_big_countries_h
#define _95_big_countries_h

SELECT name, population, area
FROM World
WHERE area > 3000000

UNION

SELECT name, population, area
FROM World
WHERE population > 25000000

#endif /* _95_big_countries_h */
