/*
 * @lc app=leetcode.cn id=64 lang=c
 *
 * [64] 最小路径和
 */

// @lc code=start

/**方法一：dp
 * 思路：
 * T:O(m*n)
 * S:O(m*n)
 */
#include<string.h>
#define min(a, b) ((a)<(b)?(a):(b))
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int m = gridSize;
    int n = gridColSize[0];
    int dp[m][n];
    memset(dp, 0, sizeof(int) * (m * n));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(i == 0 && j > 0){
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            }
            else if(j == 0 && i > 0){
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            }
            else if(i > 0 && j > 0){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
    }
    return dp[m - 1][n - 1];
}
// @lc code=end

