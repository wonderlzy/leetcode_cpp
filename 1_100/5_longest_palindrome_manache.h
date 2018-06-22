#ifndef __longest_palindrome_manache__h__
#define __longest_palindrome_manache__h__

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string strPreprocess(string s){
        int n = s.length();
        if(n == 0)
            return "^#";

        string ret = "^";
        for(int i=0; i<n; i++){
            ret += "#" + s.substr(i,1);
        }

        ret += "#$";
        return ret;
    }

    string longestPalindrome(string s) {
        string t = strPreprocess(s);
        const int len = t.length();
        int P[len];
        int R = 0, C=0;

        for(int i=1; i<len-1; i++){
            int j = 2*C-i;

            P[i] = (R>i) ? min(P[j], R-i) : 0;

            while(t[i+P[i]+1] == t[i-P[i]-1])
                P[i]++;

            if(P[i] + i > R){
                C = i;
                R = P[i]+i;
            }
        }

        //find max elment 
        int max_len = 0;
        int center_index = 0;
        for(int i=1; i<len-1; i++){
            if(P[i]>max_len){
                center_index = i;
                max_len = P[i];
            }
        }

        return s.substr((center_index-max_len-1)/2, max_len);
    }
};

#endif
/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。
示例 1：
输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。

示例 2：
输入: "cbbd"
输出: “bb"
*/