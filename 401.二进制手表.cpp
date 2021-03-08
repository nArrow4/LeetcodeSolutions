/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */
#include<bits/stdc++.h>
// @lc code=start
class Solution {
public:
    int time[10] = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
    int visited[10] = {0};
    
    vector<string> readBinaryWatch(int num) {
        std::vector<std::string> res;
        dfs(num, res, 0);
    }
    void dfs(int num, std::vector<std::string> res, int step){
        if(step == num){
            res.push_back(getTime());
            return;
        }
        for (int i = 0; i < 10; i++){
            if(!visited[i]){
                visited[i] = 1;
                dfs(num, res, step + 1);
            }
        }
    }
    std::string getTime(){

    }
};
// @lc code=end

