/*
 * @lc app=leetcode.cn id=63 lang=c
 *
 * [63] 不同路径 II
 */

// @lc code=start

/**方法一：dp
 * 思路：
 * 特别注意：障碍物在起点、终点和占满一整行、列的情况
 * T:O(n*m)
 * S:O(m*n)
 */
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1)
        return 0;
    int dp[m][n];
    memset(dp, 0, sizeof(int) * (m * n));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(i == 0 && j>0 && !obstacleGrid[i][j]){
                dp[i][j] = dp[i][j - 1];
            }
            else if(j == 0 && i>0 && !obstacleGrid[i][j]){
                dp[i][j] = dp[i - 1][j];
            }
            else if(i>0 && j>0){
                int up = obstacleGrid[i - 1][j];
                int left = obstacleGrid[i][j - 1];
                dp[i][j] += (up ? 0 : dp[i - 1][j]) + (left ? 0 : dp[i][j - 1]);
            }
        }
    }
    return dp[m - 1][n - 1];
}
// @lc code=end

