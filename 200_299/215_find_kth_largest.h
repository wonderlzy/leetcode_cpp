//
//  215_find_kth_largest.h
//  cpp_code
//
//  Created by zhongyingli on 2018/8/2.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _15_find_kth_largest_h
#define _15_find_kth_largest_h

class Solution {
public:
    int partition(vector<int>& nums, int left, int right, int pos){
        swap(nums[left], nums[pos]);
        int pivot = nums[left];
        int l = left + 1, r = right;
        while(l <= r){
            if(nums[l] < pivot && nums[r] > pivot){
                swap(nums[r--], nums[l++]);
            }
            if(nums[l] >= pivot)
                ++l;
            if(nums[r] <= pivot)
                --r;
        }
        
        swap(nums[left], nums[r]);
        return r;
    }
    
    int bfprt(vector<int>& nums, int left, int right, int k){
        if(right - left + 1 <= 5){
            sort(nums.begin()+left, nums.begin()+right+1);
            return nums[right-k+1];
        }
        
        int t = left;
        int count = (right - left + 1) / 5;
        for(int i=0; i<count; ++i){
            sort(nums.begin()+left+i*5, nums.begin()+left+(i+1)*5);
            swap(nums[t], nums[left+i*5+2]);
            ++t;
        }
        --t;
        
        int pos = (left + t) / 2;
        bfprt(nums, left, t, pos-left+1);
        
        int m = partition(nums, left, right, pos);
        if(m-left+1 == k)
            return nums[m];
        else if(m-left+1 < k)
            return bfprt(nums, m+1, right, k-(m-left+1));
        else
            return bfprt(nums, left, m-1, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return bfprt(nums, 0, nums.size()-1, k);
        
        /* min heap sort
        if(k<=0 || k>nums.size()) return -1;
        
        buildMinHeap(nums, k);
        for(int i=k; i<nums.size(); ++i){
            if(nums[i] > nums[0]){
                swap(nums[i], nums[0]);
                modifyMinHeap(nums, k, 0);
            }
        }
        return nums[0];
        */
        
        /* qsort
        if(k<=0 || k>nums.size()) return -1;
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
        */
        
        /*stl
        if(k<=0 || k>nums.size()) return -1;
        priority_queue<int> q(nums.begin(), nums.end());
        for(int i=0; i<k-1; ++i)
            q.pop();
        
        return q.top();
        */
        
        /* optimised quick sort
        if(k > nums.size() || k<=0) return -1;
        
        int left = 0, right = nums.size() - 1;
        while(true){
            int pos = partition(nums, left, right);
            if(pos == k-1) return nums[pos];
            else if(pos > k-1) right = pos-1;
            else left = pos + 1;
        }
        */
    }
    
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int l = left + 1, r = right;
        while(l <= r){
            if(nums[l] < pivot && nums[r] > pivot){
                swap(nums[r--], nums[l++]);
            }
            if(nums[l] >= pivot)
                ++l;
            if(nums[r] <= pivot)
                --r;
        }
        
        swap(nums[left], nums[r]);
        return r;
    }
    
    void modifyMinHeap(vector<int>& nums, int k, int i){
        int left = 2*i+1, right = 2*i+2;
        int small = i;
        if(left<k && nums[small]>nums[left])
            small = left;
        if(right<k && nums[small]>nums[right])
            small = right;
        
        if(small != i){
            swap(nums[small], nums[i]);
            modifyMinHeap(nums, k, small);
        }
    }
    
    void buildMinHeap(vector<int>& nums, int k){
        for(int i=k-1; i>=0; --i)
            modifyMinHeap(nums, k, i);
    }
};

#endif /* _15_find_kth_largest_h */
