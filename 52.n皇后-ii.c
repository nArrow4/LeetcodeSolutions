/*
 * @lc app=leetcode.cn id=52 lang=c
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (77.76%)
 * Likes:    104
 * Dislikes: 0
 * Total Accepted:    19.4K
 * Total Submissions: 24.9K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: 2
 * 解释: 4 皇后问题存在如下两个不同的解法。
 * [
 * [".Q..",  // 解法 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // 解法 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */

// @lc code=start

void search(int n, int* returnSize, int cur, int* tmp){
    if(cur == n){
        (*returnSize)++;
    }
    else{
        for (int i = 0; i < n; i++){
            int flag = 1;
            for (int j = 0; j < cur; j++){
                if(tmp[j] == i || j+tmp[j] == cur+i || j-tmp[j] == cur-i) {
                    flag = 0;
                    break;
                }
            }
            if(flag){
                tmp[cur] = i;
                search(n, returnSize, cur + 1, tmp);
            }
        }
    }
}

int totalNQueens(int n){
    int *tmp, *returnSize;
    tmp = (int *)malloc(sizeof(int) * n);
    returnSize = (int *)malloc(sizeof(int));
    *returnSize = 0;
    search(n, returnSize, 0, tmp);

    return (*returnSize);
}


// @lc code=end

