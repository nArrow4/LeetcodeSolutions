/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (49.94%)
 * Likes:    1773
 * Dislikes: 0
 * Total Accepted:    191.8K
 * Total Submissions: 383.8K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */

// @lc code=start


int maxSubArray(int* nums, int numsSize){
    int *dp, cnt = 0, max = *nums;
    dp = (int *)malloc(sizeof(int) * numsSize);
    *dp = *nums;
    for (int i = 1; i < numsSize; i++){
        if(dp[i-1] > 0)
            dp[i] = nums[i] + dp[i - 1];
        else
            dp[i] = nums[i];
        max = dp[i] > max ? dp[i] : max;
    }
    return max;
}
/*方法一.动态规划
一开始dp和max都等于第一个数
遍历后续数的时候判断
如果如果上一次计算的dp大于0（可以看成一个数），就加上现在的nums
否则（上一次dp小于0）dp等于现在的nums
注意：上一次的dp大于0，不管前面的数值怎么排列，对dp和是有正作用的
*/
/*方法二.分治法
每次讲数组对半分，递归求出左支、右支的最大连续子数组。
然后再求中间断开部分的最大连续数组。
最后取三者中的最大
#define     MAX(a, b, c)    ((a) > ((b) > (c) ? (b) : (c)) ? (a) : ((b) > (c) ? (b) : (c)))
int maxSubArray(int* nums, int numsSize){
    int     i               = 0;
    int     iTmp            = 0;
    int     Max_Left        = 0;
    int     Max_Right       = 0;
    int     Max_l           = 0;
    int     Max_r           = 0;
    if ((0 == numsSize) || (1 == numsSize)){
        return nums[0];
    }
    else{
        Max_Left = maxSubArray(&nums[0], (numsSize - 1) / 2);
        Max_Right = maxSubArray(&nums[(numsSize + 1) / 2], numsSize / 2);
    }
    iTmp = 0;
    Max_l = nums[(numsSize - 1) / 2];
    for (i = (numsSize - 1) / 2; i >= 0; i--){
        iTmp += nums[i];
        if (iTmp > Max_l){
            Max_l = iTmp;
        }
    }
    iTmp = Max_l;
    Max_r = Max_l;
    for (i = (numsSize + 1) / 2; i < numsSize; i++){
        iTmp += nums[i];
        if (iTmp > Max_r){
            Max_r = iTmp;
        }
    }
    return MAX(Max_Left, Max_Right, Max_r);
}
*/
/*方法三.贪心算法
从头开始遍历，每次将前面已经取和的数看成一个数
如果大于0，就加到当前数上
每次判断max是否要更新
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxSubArray(int* nums, int numsSize){
    int     i       = 0;
    int     iMax    = nums[0];
    int     iBig    = nums[0];
    for (i = 1; i < numsSize; i++){
        iBig = MAX(iBig + nums[i], nums[i]);
        if (iBig > iMax){
            iMax = iBig;
        }
    }
    return iMax;
}
*/
/*方法四.暴力破解
遍历两次，
一次取开头的数，
另一次遍历后续的数依次相加，找出max
int maxSubArray(int* nums, int numsSize){
    int     i       = 0;
    int     j       = 0;
    int     iMax    = nums[0];
    int     iTmp    = 0;
    for (i = 0; i < numsSize; i++){
        iTmp = 0;
        for (j = i; j < numsSize; j++){
            iTmp += nums[j];
            if (iTmp > iMax){
                iMax = iTmp;
            }
        }
    }
    return iMax;
}
*/
// @lc code=end

