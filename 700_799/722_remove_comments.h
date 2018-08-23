//
//  722_remove_comments.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/23.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _22_remove_comments_h
#define _22_remove_comments_h

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool blocked = false;
        string out = "";
        for (string line : source) {
            for (int i = 0; i < line.size(); ++i) {
                if (!blocked) {
                    if (i == line.size() - 1) out += line[i];
                    else {
                        string t = line.substr(i, 2);
                        if (t == "/*") blocked = true, ++i;
                        else if (t == "//") break;
                        else out += line[i];
                    }
                } else {
                    if (i < line.size() - 1) {
                        string t = line.substr(i, 2);
                        if (t == "*/") blocked = false, ++i;
                    }
                }
            }
            if (!out.empty() && !blocked) {
                res.push_back(out);
                out = "";
            }
        }
        return res;
    }
};

#endif /* _22_remove_comments_h */
