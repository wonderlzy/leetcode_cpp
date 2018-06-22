# ifndef __3_substring__no__repeat__h
# define __3_substring__no__repeat__h

# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*****
         * method 1 why not ?
        int max_len, tmp_len = 0;
        string sub_window;

        for(int i=0; i<s.size(); i++){
            size_t find_pos = sub_window.find(s[i]);
            if(find_pos == string::npos){
                sub_window.push_back(s[i]);
                tmp_len++;
            }
            else{
                tmp_len = tmp_len-(find_pos+1);
                sub_window = sub_window.substr(find_pos+1);
            }
            max_len = max_len>tmp_len ? max_len : tmp_len;
        }

        return max_len;
        */
       int max_len = 0, start = 0;
       int ASC_NUM = 255;
       int map_pos[ASC_NUM];
       fill(map_pos, map_pos+ASC_NUM, -1);

       for(int i=0; i<s.size(); i++){
            if(map_pos[s[i]]>=start){
               max_len = max_len > (i-start) ? max_len : i-start;
               start = map_pos[s[i]]+1;
            }
            map_pos[s[i]] = i;
       }

       return max_len > (s.size()-start) ? max_len : (s.size()-start);
    }
};

#endif

/*
给定一个字符串，找出不含有重复字符的最长子串的长度。
示例：
给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。
给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。
给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。
*/