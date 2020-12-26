/*
 * @lc app=leetcode.cn id=877 lang=c
 *
 * [877] 石子游戏
 */

// @lc code=start
/**方法一：动态规划
 * 思路：dp[i][j]表示剩下的石子是i到j时，二者的最大石子差。
 *          这个状态只能由dp[i+1][j],或dp[i][j-1]转换过来。
 * T:O(n^2)
 * S:O(n^2)
 */
#include<string.h>
bool stoneGame(int* piles, int pilesSize){
    if(pilesSize == 0)
        return true;
    int dp[pilesSize][pilesSize];
    memset(dp, 0, sizeof(int) * (pilesSize * pilesSize));
    for (int i = 0; i < pilesSize; i++){
        for (int j = i; j < pilesSize; j++){
            if(i == j)
                dp[i][j] = piles[i];
            else if(j == 0)
                dp[i][j] = piles[j] + (-dp[i][j - 1]);
            else if(i == pilesSize)
                dp[i][j] = piles[j] + (-dp[i + 1][j]);
            else
                dp[i][j] = fmax(piles[i] + (-dp[i + 1][j]), piles[j] + (-dp[i][j - 1]));

        }
    }
    return dp[0][pilesSize - 1];
}

/**方法二：数学方法
 * 思路：....orz
 * T:O(1)
 * S:O(1)
 */
// bool stoneGame(int* piles, int pilesSize){
//     return true;
// }
// @lc code=end

