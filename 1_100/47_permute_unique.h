//
//  47_permute_unique.h
//  cpp_code
//
//  Created by zhongyingli on 2018/6/27.
//  Copyright © 2018 zhongyingli. All rights reserved.
//

#ifndef _7_permute_unique_h
#define _7_permute_unique_h

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        if(nums.empty()) return result;
        
        map<int, int> key_vale;
        for_each(nums.begin(), nums.end(), [&key_vale](int e){
            if(key_vale.find(e) != key_vale.end())
                key_vale[e]++;
            else key_vale[e] = 1;
        });
       
        vector<pair<int, int>> elems;
        for_each(key_vale.begin(), key_vale.end(),
                 [&elems](const pair<int, int>& e) {
                     elems.push_back(e);
                 });
        
        n = nums.size();
        dfs(elems.begin(), elems.end(), result, path);
        
        return result;
    }
private:
    typedef vector<pair<int, int>>::const_iterator Iter;
    size_t n = 0;
    
    void dfs(Iter first, Iter last, vector<vector<int>>& result, vector<int>& path){
        if(path.size() == n){
            result.push_back(path);
            return ;
        }
        
        for(auto i=first; i!=last; ++i){
            int count = 0;
            for(auto dt : path){
                if( dt == i->first )
                    count++;
            }
            
            if(count < i->second){
                path.push_back(i->first);
                dfs(first, last, result, path);
                path.pop_back();
            }
        }
    }
};

#endif /* _7_permute_unique_h */
