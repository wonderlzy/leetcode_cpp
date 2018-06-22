#ifndef __z__transform__h__
#define __z__transform__h__

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1 || s.size() <=1 ) return s;
        
        int len = s.size(), k = 0, interval = (numRows<<1)-2;
        string res(len, ' ');
        
        for(int j = 0; j < len ; j += interval)//处理第一行
            res[k++] = s[j];
        for(int i = 1; i < numRows-1; i++)//处理中间行
        {
            int inter = (i<<1);
            for(int j = i; j < len; j += inter)
            {
                res[k++] = s[j];
                inter = interval - inter;
            }
        }
        for(int j = numRows-1; j < len ; j += interval)//处理最后一行
            res[k++] = s[j];
        return res;
    }
};

#endif
/*
将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：
P   A   H   N
A P L S I I G
Y   I   R

之后从左往右，逐行读取字符："PAHNAPLSIIGYIR"
实现一个将字符串进行指定行数变换的函数:
string convert(string s, int numRows);
示例 1:
输入: s = "PAYPALISHIRING", numRows = 3
输出: "PAHNAPLSIIGYIR"

示例 2:
输入: s = "PAYPALISHIRING", numRows = 4
输出: "PINALSIGYAHRPI"
解释:

P     I    N
A   L S  I G
Y A   H R
P     I
*/
