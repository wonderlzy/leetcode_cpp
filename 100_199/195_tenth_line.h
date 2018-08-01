//
//  195_tenth_line.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _95_tenth_line_h
#define _95_tenth_line_h

awk '{if(NR == 10) print $0}' file.txt


awk 'NR == 10' file.txt

sed -n 10p file.txt

tail -n +10 file.txt | head -n 1

head -n 10 file.txt | tail -n +10


#endif /* _95_tenth_line_h */
