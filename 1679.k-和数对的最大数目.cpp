/*
 * @lc app=leetcode.cn id=1679 lang=cpp
 *
 * [1679] K 和数对的最大数目
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> umap;   //key:nums[i], value:出现过的次数
        int res = 0;
        for (int i = 0; i < nums.size(); i++){
            auto target_pair = umap.find(k - nums[i]);
            if(target_pair == umap.end()){      //没有找到
                auto cur_pair = umap.find(nums[i]);
                if(cur_pair == umap.end()){
                    umap[nums[i]] = 1;
                }
                else{
                    umap[nums[i]]++;
                }
            }
            else{                               //找到了
                res+=1;
                int pair_nums = umap[k - nums[i]];
                if (pair_nums==1)
                    umap.erase(k - nums[i]);
                else umap[k-nums[i]]-=1;
            }
        }
        return res;
    }
};
// @lc code=end

