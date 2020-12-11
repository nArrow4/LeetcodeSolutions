/*
 * @lc app=leetcode.cn id=62 lang=c
 *
 * [62] 不同路径
 */

// @lc code=start

/**方法一：dp
 * 思路：
 * 
 * T:O(n*m)
 * S:O(m*n)
 */
#include<string.h>
#define max(a, b) ((a)>(b)?(a):(b))
int uniquePaths(int m, int n){
    int dp[m][n];
    memset(dp, 0, sizeof(int) * (m * n));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(i == 0){
                dp[i][j] = 1;
            }
            else if(j == 0){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}
// @lc code=end

