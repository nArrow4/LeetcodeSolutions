/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//方法一.暴力
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *aim;

    *returnSize = 0;
    aim = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize-1;i++){
        for (int j = i+1; j < numsSize;j++){
            if(nums[i]+nums[j] == target){
                aim[0] = i;
                aim[1] = j;
                *returnSize += 2;
                return aim;
            }
        }
    }
    return 0;
}
/*
暴力解法
以后还是看一下哈希吧
*/
// @lc code=end

