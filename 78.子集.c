/*
 * @lc app=leetcode.cn id=78 lang=c
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (76.89%)
 * Likes:    518
 * Dislikes: 0
 * Total Accepted:    75.6K
 * Total Submissions: 98.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void BTsubset(int *nums, int numsSize, int *returnSize, int **returnColumnSizes, int **res, int* bit, int pos){
    if(pos == numsSize){
        int index = -1;
        res[*returnSize] = (int *)malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++){
            if(bit[i]){
                res[*returnSize][++index] = nums[i];
            }
        }
        (*returnColumnSizes)[*returnSize] = index + 1;
        (*returnSize)++;
    }
    else{
        bit[pos] = 1;
        BTsubset(nums, numsSize, returnSize, returnColumnSizes, res, bit, pos + 1);
        bit[pos] = 0;
        BTsubset(nums, numsSize, returnSize, returnColumnSizes, res, bit, pos + 1);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **res, powerSet, *bit;
    powerSet = pow(2, numsSize);
    bit = (int *)malloc(sizeof(int) * numsSize);
    res = (int **)malloc(sizeof(int *) * powerSet);
    memset(bit, 0, sizeof(int) * numsSize);
    memset(res, 0, sizeof(int*) * powerSet);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * powerSet);
    BTsubset(nums, numsSize, returnSize, returnColumnSizes, res, bit, 0);
    
    return res;
}


// @lc code=end

