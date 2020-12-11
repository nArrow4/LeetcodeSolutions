/*
 * @lc app=leetcode.cn id=118 lang=c
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (66.01%)
 * Likes:    271
 * Dislikes: 0
 * Total Accepted:    68.4K
 * Total Submissions: 103.5K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **res;
    res = (int **)malloc(sizeof(int *) * numRows);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
    for (int row = 1; row <= numRows; row++){
        res[*returnSize] = malloc(sizeof(int) * row);
        res[*returnSize][0] = 1;
        res[*returnSize][row - 1] = 1;
        for (int col = 1; col < row-1; col++){
            res[*returnSize][col] = res[*returnSize - 1][col - 1] + res[*returnSize - 1][col];
        }
        (*returnColumnSizes)[*returnSize] = row;
        (*returnSize)++;
    }
    return res;
}


// @lc code=end

