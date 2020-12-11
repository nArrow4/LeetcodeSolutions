/*
 * @lc app=leetcode.cn id=119 lang=c
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (60.50%)
 * Likes:    132
 * Dislikes: 0
 * Total Accepted:    45.3K
 * Total Submissions: 74.8K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int *res;
    res = (int *)malloc(sizeof(int) * (rowIndex+1));
    *returnSize = rowIndex+1;
    for (int row = 1; row <= rowIndex + 1; row++){
        res[0] = 1;
        res[row - 1] = 1;
        for (int col = row - 2; col >= 1; col--){
            res[col] = res[col] + res[col - 1];
        }
    }
    return res;
}


// @lc code=end

