//
//  197_rising_temperature.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _97_rising_temperature_h
#define _97_rising_temperature_h

SELECT w1.Id FROM Weather w1, Weather w2
WHERE w1.Temperature > w2.Temperature AND DATEDIFF(w1.RecordDate, w2.RecordDate) = 1;

SELECT w1.Id FROM Weather w1, Weather w2
WHERE w1.Temperature > w2.Temperature AND TO_DAYS(w1.RecordDate) = TO_DAYS(w2.RecordDate) + 1;

SELECT w1.Id FROM Weather w1, Weather w2
WHERE w1.Temperature > w2.Temperature AND SUBDATE(w1.RecordDate, 1) = w2.RecordDate;

SELECT Id FROM (
                SELECT CASE WHEN Temperature > @pre_t AND DATEDIFF(RecordDate, @pre_d) = 1 THEN Id ELSE NULL END AS Id,
                @pre_t := Temperature, @pre_d := RecordDate
                FROM Weather, (SELECT @pre_t := NULL, @pre_d := NULL) AS init ORDER BY Date ASC
                ) id WHERE Id IS NOT NULL;

#endif /* _97_rising_temperature_h */
