/*
 * @lc app=leetcode.cn id=51 lang=c
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (68.58%)
 * Likes:    364
 * Dislikes: 0
 * Total Accepted:    33K
 * Total Submissions: 48K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**方法一：
 * 
 * 
 * 
 * 
 */
// #include<stdlib.h>

// bool check(int** used, int n, int x, int y){
//     printf("%d %d \n", y, x);
//     if(used[y][x] == 1) return false;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < n; j++){
//             if(used[i][j] && i == y || j == x || j - i == x - y || i + j == x + y){
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// void dfs(int n, char*** res, int*returnSize, int **returnColumnSizes, int** used, int row){
//     if(row == n){               //出口
//         char **board = (char **)malloc(sizeof(char *) * n);
//         for (int i = 0; i < n; i++){
//             board[i] = (char *)malloc(sizeof(char) * n);
//             for (int j = 0; j < n; j++){
//                 if(used[i][j]){
//                     board[i][j] = 'Q';
//                 }
//                 else
//                     board[i][j] = '.';
//             }
//         }
//         res = (char ***)realloc(res, sizeof(char **) * (*returnSize + 1));
//         res[*returnSize] = board;
//         (*returnSize)++;
//         return;
//     }
//     for (int c = 0; c < n; c++){
//         printf("%d %d \n", row, c);
//         if(check(used, n, c, row)){
//             used[row][c] = 1;
//             dfs(n, res, returnSize, returnColumnSizes, used, row + 1);
//         }
//     }
//     return;
// }

// char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
//     char ***res = (char***)malloc(sizeof(char**)*501);
//     *returnSize = 0;
//     int *used[n];
//     for (int i = 0; i < n; i++){
//         used[i] = (int*)malloc(sizeof(int) * n);
//     }
//     dfs(n, res, returnSize, returnColumnSizes, used, 0);
//     *returnColumnSizes = (int *)malloc(sizeof(int) * *returnSize);
//     for (int i = 0; i < *returnSize; i++){
//         returnColumnSizes[0][i] = n;
//     }
//     return res;
// }

// @lc code=end

