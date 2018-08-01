//
//  193_valid_phone_num.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _93_valid_phone_num_h
#define _93_valid_phone_num_h

awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt

sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt

grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt

#endif /* _93_valid_phone_num_h */
