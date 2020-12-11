/*
 * @lc app=leetcode.cn id=40 lang=c
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (60.89%)
 * Likes:    231
 * Dislikes: 0
 * Total Accepted:    49.3K
 * Total Submissions: 80.7K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAX_SIZE 500

static int compare(const int* a, const int* b)
{
    return *(int*)a - *(int*)b;
}

static void dfs(int* candidates, int candidatesSize, int target,
                int* returnSize, int** returnColumnSizes,
                int** ppRes, int* pBuffer, bool* pbUsed, 
                int indexOfCan, int indexOfBuf)
{
    int index = 0;

    if (0 == target)
    {
        ppRes[*returnSize] = (int*)malloc(indexOfBuf * sizeof(int));
        memcpy(ppRes[*returnSize], pBuffer, indexOfBuf * sizeof(int));
        (*returnColumnSizes)[*returnSize] = indexOfBuf;
        (*returnSize)++;
    }
    else if (0 < target)
    {
        for (index = indexOfCan; index <= candidatesSize - 1; index++)
        {
            if (false == pbUsed[index])
            {
                if (indexOfCan != index && candidates[index - 1] == candidates[index] && false == pbUsed[index])
                {
                    continue;
                }

                pbUsed[index] = true;

                pBuffer[indexOfBuf] = candidates[index];

                dfs(candidates, candidatesSize, target - candidates[index],
                    returnSize, returnColumnSizes,
                    ppRes, pBuffer, pbUsed,
                    index + 1, indexOfBuf + 1); // 因为不重复，所以从下一个开始（indexOfCan + 1）

                pbUsed[index] = false;
            }
        }
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target,
                      int* returnSize, int** returnColumnSizes)
{
    qsort(candidates, candidatesSize, sizeof(int), compare);

    int indexOfCan = 0;
    int indexOfBuf = 0;

    int** ppRes = (int**)malloc(MAX_SIZE * sizeof(int*));
    int* pBuffer = (int*)malloc(target * sizeof(int));
    bool* pbUsed = (bool*)malloc(candidatesSize);
    memset(pbUsed, false, candidatesSize);

    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(MAX_SIZE * sizeof(int));

    dfs(candidates, candidatesSize, target,
        returnSize, returnColumnSizes,
        ppRes, pBuffer, pbUsed,
        indexOfCan, indexOfBuf);

    return ppRes;
}
/*有错
#define MAX_SIZE 5000
int IsSameArray(int* arr1, int* arr2){
    if(sizeof(arr1) != sizeof(arr2))
        return 0;
    int flag = 1, len = sizeof(arr1) / sizeof(int);
    for (int i = 0; i < len; i++){
        if(arr1[i] != arr2[i])
            flag = 0;
    }
    return flag;
}

void backTracking(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int** res, int* track, int pos, int index){
    if(0 == target){
        int flag = 1;
        for (int i = 0; i < *returnSize; i++){
            if(IsSameArray(track, res[i])){
                flag = 0;
                break;
            }
        }
        if(flag){
            res[*returnSize] = (int *)malloc(sizeof(int) * pos);
            memcpy(res[*returnSize], track, sizeof(int) * pos);
            (*returnColumnSizes)[*returnSize] = pos;
            (*returnSize)++;
        }
        return;
    }
    else if(0 > target){
        return;
    }
    else{
        for (int i = index;i<candidatesSize; i++){
            track[pos] = candidates[i];
            backTracking(candidates, candidatesSize, target - track[pos], returnSize, returnColumnSizes, res, track, pos+1, i+1);
        }
    }
}

int cmp(void* a, void* b){
    return *(int *)a - *(int *)b;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * MAX_SIZE);
    int *track = (int *)malloc(sizeof(int) * (target+1));
    memset(track, 0, sizeof(int) * (target + 1));
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_SIZE);
    if(target == 1){
        int flag = 0;
        for (int i = 0; i < candidatesSize; i++){
            if(candidates[i] == 1)
                flag = 1;
        }
        if(flag){
            res[*returnSize] = (int *)malloc(sizeof(int)*2);
            res[*returnSize][0] = 1;
            (*returnColumnSizes)[*returnSize] = 1;
            (*returnSize)++;
        }
        return res;
    }
    backTracking(candidates, candidatesSize, target, returnSize, returnColumnSizes, res, track, 0, 0);
    return res;
}
*/

// @lc code=end

