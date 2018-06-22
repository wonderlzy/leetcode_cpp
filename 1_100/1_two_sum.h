# ifndef __1__two__sum__h__
# define __1__two__sum__h__
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size()<2)
            return vector<int>(2);
        
        map<int, int> diff_map;
        vector<int> ret_vec;
        for(int i=0; i<nums.size(); i++)
            diff_map[nums[i]] = i;

        for(int j=0; j<nums.size(); j++){
            const int pair_key = target-nums[j];
            if(diff_map.find(pair_key)!=diff_map.end() && diff_map[pair_key]>j){
                ret_vec.push_back(j);
                ret_vec.push_back(diff_map[pair_key]);
                break;
            }
        }

        return ret_vec;
    }
};
#endif

/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/