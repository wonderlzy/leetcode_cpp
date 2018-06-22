# ifndef __longest_palindrome__h__
# define __longest_palindrome__h__

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        bool f[n][n];
        fill_n(&f[0][0], n*n, false);

        size_t max_len = 1, start = 0;

        for(int i=0; i<n; i++){
            f[i][i] = true;

            for(int j=0; j<i; j++){
                f[j][i] = (s[j]==s[i] && (i-j<2 || f[j+1][i-1]));

                if(f[j][i] && (i-j+1)>max_len){
                    max_len = i-j+1;
                    start = j;
                }
            }
        }

        return s.substr(start, max_len);
    }
};

#endif