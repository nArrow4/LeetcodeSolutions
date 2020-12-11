/*
 * @lc app=leetcode.cn id=221 lang=c
 *
 * [221] 最大正方形
 */

// @lc code=start

#include<string.h>
#define max(a, b) ((a)>(b)?(a):(b))
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int m = matrixSize;
    int n = matrixColSize[0];
    int dp[m][n], max = 0;
    memset(dp, 0, sizeof(int) * (m * n));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(i == 0 || j == 0){
                dp[i][j] = (matrix[i][j] == '1');
            }
            else if(dp[i-1][j]>=dp[i-1][j-1] && dp[i][j-1]>=dp[i-1][j-1] && matrix[i][j] == '1'){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = 0;
            }
            printf("%d ", dp[i][j]);
            max = max(max, dp[i][j]);
        }
    }
    return max * max;
}
// @lc code=end

