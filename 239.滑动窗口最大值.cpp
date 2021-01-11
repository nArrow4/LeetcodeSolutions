/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int> res;
        // priority_queue<pair<int, int>> q;
        // for (int i = 0; i < k; i++){
        //     q.emplace(i, nums[i]);
        // }
        // res.push_back(q.top().second);
        // for (int i = k; i < nums.size(); i++){
        //     q.emplace(i, nums[i]);
        //     if(q.top().first == i-k){
        //         q.pop();
        //     }
        //     res.push_back(q.top().second);
        // }
        // return res;
        priority_queue<pair<int, int>> q;
        for(int i=0;i<k;i++){
            q.emplace(nums[i], i);
        }
        vector<int> ans = {q.top().first};
        for(int i=k;i<nums.size();i++){
            q.emplace(nums[i], i);
            while(q.top().second <= i-k){
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
// @lc code=end

