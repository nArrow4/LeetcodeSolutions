/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */
#include<bits/stdc++.h?
using namespace std;
// @lc code=start
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            if(!dp[i]){
                dp[i] = dp[i-1]+dp[i-2];
            }
        }
        return dp[n];
    }
};
// @lc code=end

