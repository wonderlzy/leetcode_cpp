//
//  585_investments_in2016.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/21.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _85_investments_in2016_h
#define _85_investments_in2016_h

SELECT
SUM(insurance.TIV_2016) AS TIV_2016
FROM
insurance
WHERE
insurance.TIV_2015 IN
(
 SELECT
 TIV_2015
 FROM
 insurance
 GROUP BY TIV_2015
 HAVING COUNT(*) > 1
 )
AND CONCAT(LAT, LON) IN
(
 SELECT
 CONCAT(LAT, LON)
 FROM
 insurance
 GROUP BY LAT , LON
 HAVING COUNT(*) = 1
 )
;

#endif /* _85_investments_in2016_h */
