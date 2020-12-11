/*
 * @lc app=leetcode.cn id=213 lang=c
 *
 * [213] 打家劫舍 II
 */

// @lc code=start

/**方法一：dp
 * 思路：分两种情况
 *      1.偷第一家      [:numsSize]
 *      2.不偷第一家    [1:]
 * 相似题：
 *      1.198打家劫舍
 *      2.213打家劫舍2
 * T:O(n)
 * S:O(n)
 */
#include<string.h>
#define max(a, b) ((a)>(b)?(a):(b))
int rob(int* nums, int numsSize){
    int dp1[numsSize];
    int dp2[numsSize];
    memset(dp1, 0, sizeof(int) * numsSize);
    memset(dp2, 0, sizeof(int) * numsSize);
    int max = 0;
    if(numsSize == 1)
        return nums[0];
    else if(numsSize == 2){
        return max(nums[0], nums[1]);
    }
    for (int i = 0; i < numsSize; i++){
        if(i == 0){
            dp1[i] = nums[i];
            dp2[i] = 0;
        }
        else if(i == 1){
            dp1[i] = max(nums[i], nums[i - 1]);
            dp2[i] = nums[i];
        }
        else{
            if(i<numsSize -1)
                dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
            if(i>0)
                dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }
        max = max(max, dp1[i]);
        max = max(max, dp2[i]);
    }
    return max;
}
// @lc code=end

