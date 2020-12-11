/*
 * @lc app=leetcode.cn id=90 lang=c
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (59.45%)
 * Likes:    184
 * Dislikes: 0
 * Total Accepted:    27.7K
 * Total Submissions: 46.5K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* arr1,const void* arr2){
    return *(int *)arr1 - *(int *)arr2;
}

int IsSameArray(int* arr1, int* arr2, int numsSize){
    int flag = 1;
    for (int i = 0; i < numsSize; i++){
        if(arr1[i] != arr2[i]){
            flag = 0;
            break;
        }
    }
    return flag;
}

void BTsubset(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** res, int* bit, int pos){
    if(pos == numsSize){
        int index = -1;
        res[*returnSize] = (int *)malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++){
            if(bit[i]){
                res[*returnSize][++index] = nums[i];
            }
        }
        for (int i = 0; i < *returnSize; i++){
            if(IsSameArray(res[*returnSize], res[i], numsSize))
                return;
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

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **res, powerSet, *bit;
    powerSet = pow(2, numsSize);
    bit = (int *)malloc(sizeof(int) * numsSize);
    res = (int **)malloc(sizeof(int *) * powerSet);
    memset(bit, 0, sizeof(int) * numsSize);
    memset(res, 0, sizeof(int*) * powerSet);
    (*returnSize) = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * powerSet);
    qsort(nums, numsSize, sizeof(int), cmp);
    BTsubset(nums, numsSize, returnSize, returnColumnSizes, res, bit, 0);
    return res;
}


// @lc code=end

