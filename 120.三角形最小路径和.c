/*
 * @lc app=leetcode.cn id=120 lang=c
 *
 * [120] 三角形最小路径和
 */

// @lc code=start

/**方法一：dp
 * 思路：dp[i][j]表示到达（i，j）位置时的最短路径
 *              转移方程只需考虑i-1层到底i层
 * T:O(m*n)
 * S:O(m*n)
 */
#include<limits.h>
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int *dp[triangleSize], min = INT_MAX;
    for (int i = 0; i < triangleSize; i++){
        dp[i] = (int*)malloc(sizeof(int) * (triangleColSize[i]));
        memset(dp[i], INT_MAX, sizeof(int) * triangleColSize[i]);
    }
    for (int i = 0; i < triangleSize; i++){
        for (int j = 0; j < triangleColSize[i]; j++){
            if(i == 0){
                dp[i][j] = triangle[i][j];
            }
            else{
                dp[i][j] = triangle[i][j] + min(dp[i - 1][min(j, triangleColSize[i-1] - 1)], dp[i - 1][max(j - 1, 0)]);
            }
        }
    }
    for (int i = 0; i < triangleColSize[triangleSize - 1]; i++){
        min = min(min, dp[triangleSize - 1][i]);
    }
    return min;
}


// @lc code=end

