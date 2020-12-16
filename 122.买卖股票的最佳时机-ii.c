/*
 * @lc app=leetcode.cn id=122 lang=c
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start

/**方法一：暴力
 * 思路：每次找峰顶和峰底，注意开头和结尾的递增/递减
 * T:O(n)
 * S:O(1)
 *
int maxProfit(int* prices, int pricesSize){
    int min, max, ans = 0;
    if(pricesSize == 1 || pricesSize == 0)
        return 0;
    int flag = (prices[1] > prices[0]);     //1 for up ,0 for down
    min = max = prices[0];
    for (int i = 0; i < pricesSize; i++){
        if(i > 0 && prices[i - 1] < prices[i] && flag == 0){
            flag = 1;
            min = prices[i - 1];
        }
        else if(i > 0 && prices[i - 1] > prices[i] && flag == 1){
            flag = 0;
            max = prices[i - 1];
            ans += max - min;
        }
    }
    if(flag && pricesSize > 0)
        ans += prices[pricesSize - 1] - min;
    return ans;
}
*/

/**方法二：动态规划
 * 思路：dp[i][0]表示第i天，没股票的最大利润；dp[i][1]表示第i天，有股票的最大利润
 *          1. 如果第i天没股票，只可能是
 *              1）第i-1天没股票，dp[i][0] = dp[i-1][0]
 *              2）第i-1天有股票，第i天卖出股票。dp[i][0] = dp[i-1][1] + prices[i]
 *              dp[i][0]为二者较大值
 *          2. 如果第i天有股票，只可能是
 *              1）第i-1天有股票，dp[i][1] = dp[i-1][1]
 *              2）第i-1天没股票，第i天买入股票。dp[i][1] = dp[i][0] - prices[i]
 *              dp[i][1]为二者较大值
 * T:O(n)
 * S:O(n)
 *
int maxProfit(int* prices, int pricesSize) {
    int dp[pricesSize][2];
    dp[0][0] = 0, dp[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; ++i) {
        dp[i][0] = fmax(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = fmax(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[pricesSize - 1][0];
}
*/
/**方法二：贪心
 * 思路：只要某一天价格比前一天高，就在前一天买入，当天卖出。
 * T:O(n)
 * S:O(1)
 */
int maxProfit(int* prices, int pricesSize) {
    int ans = 0;
    for (int i = 1; i < pricesSize; i++){
        ans += fmax(0, prices[i] - prices[i - 1]);
    }
    return ans;
}
// @lc code=end

