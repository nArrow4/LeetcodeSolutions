/*
 * @lc app=leetcode.cn id=486 lang=c
 *
 * [486] 预测赢家
 */

// @lc code=start

/**方法一：dp
 * 思路：
 * 
 * 
 */
// bool PredictTheWinner(int* nums, int numsSize){
//     int dp[numsSize][numsSize];
//     memset(dp, 0, sizeof(int) * numsSize * numsSize);
//     for (int i = 0; i < numsSize; i++){
//         for (int j = i; j < numsSize; j++){
//             if(i == j){
//                 dp[i][j] = nums[i];
//             }
//             else if(i == numsSize-1){
//                 dp[i][j] = nums[i] + (-dp[i][j - 1]);
//             }
//             else if(j == 0){
//                 dp[i][j] = nums[i] + (-dp[i + 1][j]);
//             }
//             else{
//                 dp[i][j] = fmax(nums[i] + (-dp[i + 1][j]), nums[j] + (-dp[i][j - 1]));
//             }
//             printf("%d ", dp[i][j]);
//         }
//     }
//     return dp[0][numsSize-1];
// }
// @lc code=end

