/*
 * @lc app=leetcode.cn id=46 lang=c
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (74.51%)
 * Likes:    583
 * Dislikes: 0
 * Total Accepted:    97K
 * Total Submissions: 130K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
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

void backTrackingPermute(int* nums, int numsSize, int* returnSize, int** returnColumSizes, int** res){
    static int slow = 0;
    int fast;
    //结束条件（不继续调用递归）
    if(slow == numsSize){
        //*returnSize为当前储存的排列+1，于是为开辟新空间储存当前的排列，长度当然为numsSize
        *(res + *returnSize) = (int *)malloc(sizeof(int) * numsSize);
        //nums为当前排列
        memcpy(res[*returnSize], nums, numsSize * sizeof(int));
        //储存当前排列的个数
        (*returnColumSizes)[*returnSize] = numsSize;
        //已排列的个数+1
        (*returnSize)++;
    }
    //将nums中的顺序打乱，生成新排列
    /*
    以[1,2,3]为例，刚遍历时slow其实大于fast，每次进入递归、for循环的时候取相等
    当把第一种排序储存好了之后，回溯，slow和fast都变为2（fast不是static）
    此时继续循环，fast向后遍历，与slow交换······
    */
    else{
        //slow逐层增加，fast从slow开始向后遍历，每次将对应的值与slow交换
        for (fast = slow; fast < numsSize; fast++){
            //交换值，slow增加，进入下一层
            swap(nums + slow, nums + fast);
            slow++;
            //达到最后一层，储存后跳出
            backTrackingPermute(nums, numsSize, returnSize, returnColumSizes, res);
            //回溯，将slow和fast交换回来
            slow--;
            swap(nums + slow, nums + fast);
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    //NAX_SIZE为全排列的总数
    int **res = (int **)malloc(sizeof(int *) * MAX_SIZE);
    //*returnSize为res中已储存的排列数
    *returnSize = 0;
    //*returnColumnSizes为储存排列数的个数
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_SIZE);

    backTrackingPermute(nums, numsSize, returnSize, returnColumnSizes, res);

    return res;
}


// @lc code=end

