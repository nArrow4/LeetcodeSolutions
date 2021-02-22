/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */
#include<bits/stdc++.h>
// @lc code=start
/**
 * 方法：
 * 思路：用哈希表映射，总个数、起始点、终止点
 * 注意：总个数相同的，取最短
 */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        std::unordered_map<int, std::vector<int>> umap;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if(umap.count(nums[i])){
                umap[nums[i]][0]++;
                umap[nums[i]][2] = i;
            }
            else{
                umap[nums[i]] = {1, i, i};
            }
        }
        int max = INT_MIN;
        int maxLen = 0;
        for (int i = 0; i < n; i++){
            if(umap[nums[i]][0] > max){
                max = umap[nums[i]][0];
                maxLen = umap[nums[i]][2] - umap[nums[i]][1] + 1;
            }
            else if(umap[nums[i]][0] == max){
                maxLen = fmin(umap[nums[i]][2] - umap[nums[i]][1] + 1, maxLen);
            }
        }
        return maxLen;
    }
};
// @lc code=end

