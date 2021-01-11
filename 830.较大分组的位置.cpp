/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        char cur = s[0];
        int cnt=1, start = 0, len = s.size();
        for(int i=1;i<len;i++){
            if(s[i] == cur){
                cnt++;
            }
            else{
                if(cnt >= 3){
                    res.push_back({start, i-1});
                }
                cur = s[i], start = i;
                cnt = 1;
            }
        }
        if(cnt >= 3){
            res.push_back({start, len-1});
        }
        return res;
    }
};
// @lc code=end

