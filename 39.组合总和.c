/*
 * @lc app=leetcode.cn id=39 lang=c
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (68.65%)
 * Likes:    586
 * Dislikes: 0
 * Total Accepted:    79.1K
 * Total Submissions: 115.2K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [2,3,6,7], target = 7,
 * 所求解集为:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,3,5], target = 8,
 * 所求解集为:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
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
void backTracking(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int** res, int* track, int pos, int index){
    if(0 == target){
        res[*returnSize] = (int *)malloc(sizeof(int) * pos);
        memcpy(res[*returnSize], track, sizeof(int) * pos);
        (*returnColumnSizes)[*returnSize] = pos;
        (*returnSize)++;
        return;
    }
    else if(0 > target){
        return;
    }
    else{
        for (int i = index;i<candidatesSize; i++){
            track[pos] = candidates[i];
            backTracking(candidates, candidatesSize, target - track[pos], returnSize, returnColumnSizes, res, track, pos+1, i);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * MAX_SIZE);
    int *track = (int *)malloc(sizeof(int) * (target+1));
    memset(track, 0, sizeof(int) * (target + 1));
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_SIZE);
    backTracking(candidates, candidatesSize, target, returnSize, returnColumnSizes, res, track, 0, 0);
    return res;
}


// @lc code=end

