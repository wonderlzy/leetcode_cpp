//
//  17_letter_combination.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/14.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _7_letter_combination_h
#define _7_letter_combination_h

class Solution {
public:
    Solution(){
        num_key.insert(pair<int, vector<string>>(2, vector<string>({"a", "b", "c"})));
        num_key.insert(pair<int, vector<string>>(3, vector<string>({"d", "e", "f"})));
        num_key.insert(pair<int, vector<string>>(4, vector<string>({"g", "h", "i"})));
        num_key.insert(pair<int, vector<string>>(5, vector<string>({"j", "k", "l"})));
        num_key.insert(pair<int, vector<string>>(6, vector<string>({"m", "n", "o"})));
        num_key.insert(pair<int, vector<string>>(7, vector<string>({"p", "q", "r", "s"})));
        num_key.insert(pair<int, vector<string>>(8, vector<string>({"t", "u", "v"})));
        num_key.insert(pair<int, vector<string>>(9, vector<string>({"w", "x", "y", "z"})));
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.length()==0) return result;
        
        if(digits.length()==1)
            return num_key[int(digits[0]-'0')];
        
        if(digits.length()==2)
            return combinationTwoLetters(num_key[digits[0]-'0'], num_key[digits[1]-'0']);
        
        vector<string> left = letterCombinations(digits.substr(0, digits.length()/2));
        vector<string> right = letterCombinations(digits.substr(digits.length()/2, digits.length()-digits.length()/2));
            
        return combinationTwoLetters(left, right);
    }
    
    vector<string> combinationTwoLetters(vector<string> &left, vector<string> &right){
        vector<string> result ;
        for(auto i=left.begin(); i<left.end(); ++i)
            for(auto j=right.begin(); j<right.end(); ++j)
                result.push_back(*i + *j);
        
        return result;
    }
    
private:
    map<int, vector<string>> num_key;
};

#endif /* _7_letter_combination_h */
