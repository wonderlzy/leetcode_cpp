//
//  804_unique_morse_representation.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/24.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _04_unique_morse_representation_h
#define _04_unique_morse_representation_h

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for (string word : words) {
            string t = "";
            for (char c : word) t += morse[c - 'a'];
            s.insert(t);
        }
        return s.size();
    }
};

#endif /* _04_unique_morse_representation_h */
