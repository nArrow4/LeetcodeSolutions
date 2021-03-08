/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 1));   // dp表示第i个数到第j个数是否为回文串
        // 构造状态转移方程的时候需要 dp[i+1][j-1]已知
        for (int i = n - 1; i >= 0; i--){
            for (int j = i + 1; j < n; j++){
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
        vector<int> min(n, INT_MAX);         // 表示前i个数的最少分割次数
        for (int i = 0; i < n; i++){
            if(dp[0][i]){           // o-i是回文串，不用分割
                min[i] = 0;
            }
            else{                   // 0-i不是回文串，需要找到离i最近的回文串
                for (int j = 0; j < i; j++){
                    if(dp[j + 1][i]){
                        min[i] = fmin(min[i], min[j] + 1);
                    }
                }
            }
        }
        return min[n - 1];
    }
};
// @lc code=end

