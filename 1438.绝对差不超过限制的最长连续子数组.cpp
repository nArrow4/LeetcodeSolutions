/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 *
 * [1438] 绝对差不超过限制的最长连续子数组
 */
#include <bits/stdc++.h>
// @lc code=start
/**
 * 方法一：滑动窗口+有序集合
 * 思路：
 * 总结：
 * 1. 最长连续数组类的题目用滑动窗口做
 * 2. 需要使用一段序列中的最大值和最小值的，用multiset
 */
// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, int limit) {
//         std::multiset<int> ms;
//         int len = nums.size();
//         int left = 0;
//         int right = 0;
//         int ret = 0;
//         while(right < len){
//             ms.insert(nums[right]);
//             while(*ms.rbegin() - *ms.begin() > limit){
//                 ms.erase(ms.find(nums[left]));
//                 left++;
//             }
//             ret = fmax(ret, right - left + 1);
//             right++;
//         }
//         return ret;
//     }
// };
/**
 * 方法二：滑动窗口+单调队列
 * 思路：
 * 总结：
 * 
 */
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        std::deque<int> maxQ, minQ;
        int n = nums.size();
        int ret = 0;
        int left = 0;
        int right = 0;
        while(right < n){
            while(!maxQ.empty() && maxQ.back() < nums[right])
                maxQ.pop_back();
            while(!minQ.empty() && minQ.back() > nums[right])
                minQ.pop_back();
            maxQ.push_back(nums[right]);
            minQ.push_back(nums[right]);
            while(!maxQ.empty() && !minQ.empty() && maxQ.front() - minQ.front() > limit){
                if(minQ.front() == nums[left]){
                    minQ.pop_front();
                }
                if(maxQ.front() == nums[left]){
                    maxQ.pop_front();
                }
                left++;
            }
            ret = fmax(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};
// @lc code=end

