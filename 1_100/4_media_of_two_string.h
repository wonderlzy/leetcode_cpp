# ifndef __4__media__of__two__string__h__
# define __4__media__of__two__string__h__

# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
        const int m = nums1.size();
        const int n = nums2.size();
        int total = m + n;
        if(total & 0x1)
            return findMedianData(nums1.begin(), m, nums2.begin(), n, total/2+1);
        else{
            return (findMedianData(nums1.begin(), m, nums2.begin(), n, total/2) + \
                    findMedianData(nums1.begin(), m, nums2.begin(), n, total/2+1)) / 2.0;
        }
    }

    double findMedianData(vector<int>::const_iterator A, int m, vector<int>::const_iterator B, int n, int k){
        //make sure m is equal or smaller than n
        if(m>n)
            return findMedianData(B, n, A, m, k);
        if(m==0)
            return *(B+k-1);
        if(k==1)
            return min(*A, *B);
        
        int index_a = min(k/2, m);
        int index_b = k-index_a;

        if(A[index_a-1]>B[index_b-1])
            return findMedianData(A, m, B+index_b, n-index_b, k-index_b);
        if(A[index_a-1]<B[index_b-1])
            return findMedianData(A+index_a, m-index_a, B, n, k-index_a);
        else 
            return A[index_a-1];
    }   
};

# endif

/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
示例 1:
nums1 = [1, 3]
nums2 = [2]

中位数是 2.0

示例 2:
nums1 = [1, 2]
nums2 = [3, 4]

中位数是 (2 + 3)/2 = 2.5
*/