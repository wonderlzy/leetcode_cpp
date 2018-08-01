//
//  194_transpose_file.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/1.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _94_transpose_file_h
#define _94_transpose_file_h

awk '{
for (i = 1; i <= NF; ++i) {
    if (NR == 1) s[i] = $i;
        else s[i] = s[i] " " $i;
            }
} END {
    for (i = 1; s[i] != ""; ++i) {
        print s[i];
    }
}' file.txt



while read -a line; do
for ((i = 0; i < "${#line[@]}"; ++i)); do
a[$i]="${a[$i]} ${line[$i]}"
done
done < file.txt
for ((i = 0; i < ${#a[@]}; ++i)); do
echo ${a[i]}
done

#endif /* _94_transpose_file_h */
