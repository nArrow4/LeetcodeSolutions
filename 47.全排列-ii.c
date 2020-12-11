/*
 * @lc app=leetcode.cn id=47 lang=c
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (57.76%)
 * Likes:    252
 * Dislikes: 0
 * Total Accepted:    48.1K
 * Total Submissions: 83.2K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 5000
void swap(int* num1, int* num2){
    int tmp;
    tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}
int sameArray(int* arr1, int* arr2, int numsSize){
    for (int i = 0; i < numsSize; i++){
        if(arr1[i] != arr2[i])
            return 0;
    }
    return 1;
}
void backTrackingPermute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** res){
    static int slow = 0;
    int fast = 0;
    if(slow == numsSize){
        for (int i = 0; i < *returnSize; i++){
            if(sameArray(nums, res[i], numsSize) == 1)
                return;
        }
        *(res + *returnSize) = (int *)malloc(sizeof(int) * numsSize);
        memcpy(res[*returnSize], nums, sizeof(int) * numsSize);
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
    }
    else{
        for (fast = slow; fast < numsSize; fast++){
            swap(nums + fast, nums + slow);
            slow++;
            backTrackingPermute(nums, numsSize, returnSize, returnColumnSizes, res);
            slow--;
            swap(nums + fast, nums + slow);
        }
    }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * MAX_SIZE);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_SIZE);

    backTrackingPermute(nums, numsSize, returnSize, returnColumnSizes, res);

    return res;
}


// @lc code=end

