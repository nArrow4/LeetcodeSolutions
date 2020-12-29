/*
 * @lc app=leetcode.cn id=123 lang=c
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start

/**方法一：动态规划
 * 思路：将天数以i为界分为两部分，分别计算0-i和i-n两段的最大利润，然后求和再求最大。
 * T:O(n)
 * S:O(n)
 */
int maxProfit(int* prices, int pricesSize){
    if(pricesSize == 0 || pricesSize == 1)
        return 0;
    int dp[pricesSize];
    int min = prices[0];
    for (int i = 0; i < pricesSize; i++){
        min = fmin(min, prices[i]);
        dp[i] = prices[i] - min;
    }
    int max = 0, value = 0, ans = 0;
    for (int i = pricesSize - 1; i >= 1; i--){
        max = fmax(max, prices[i]);
        value = fmax(value, max - prices[i]);
        ans = fmax(ans, value + dp[i]);
    }
    return ans;
}
// @lc code=end

