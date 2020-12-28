/*
 * @lc app=leetcode.cn id=121 lang=c
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start

/**方法一：动态规划
 * 思路：dp[i]表示前i天能卖出的最大利润，用min记录前i天股票的最低价
 * T:O(n)
 * S:O(n)
 */
int maxProfit(int* prices, int pricesSize){
    if(pricesSize == 0)
        return 0;
    int min = prices[0];
    int dp[pricesSize];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < pricesSize; i++){
        dp[i] = fmax(dp[i - 1], prices[i] - min);
        min = fmin(min, prices[i]);
    }
    return dp[pricesSize - 1];
}


// @lc code=end

