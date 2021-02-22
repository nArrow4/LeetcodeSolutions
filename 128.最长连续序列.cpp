/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include<bits/stdc++.h>
// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> mset;
        for(auto &num : nums){
            mset.insert(num);
        }

        int maxLen = 0;

        for(auto &num : mset){
            if(!mset.count(num-1)){
                int curNum = num;
                int curLen = 1;

                while(mset.count(curNum+1)){
                    curNum++;
                    curLen++;
                }

                maxLen = fmax(maxLen, curLen);
            }
        }
        return maxLen;
    }
};
// @lc code=end

