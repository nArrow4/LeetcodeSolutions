/*
 * @lc app=leetcode.cn id=198 lang=c
 *
 * [198] 打家劫舍
 */

// @lc code=start

/**方法一：dp
 * 思路:dp[i]表示i个房屋能偷到的最大金额
 *              1.偷第i家，dp[i] = dp[i-2] + nums[i]
 *              2.不偷第i家，dp[i] = dp[i-1]
 * T:O(n)
 * S:O(n)
 */
#define max(a, b) ((a)>(b)?(a):(b))
int rob(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    int dp[numsSize], max = 0;
    for (int i = 0; i < numsSize; i++){
        if(i == 0){
            dp[i] = nums[i];
        }
        else if(i == 1){
            dp[i] = max(nums[i - 1], nums[i]);
        }
        else{
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        max = max(max, dp[i]);
    }
    return max;
}
// @lc code=end

