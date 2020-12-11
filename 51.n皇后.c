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

#include<stdlib.h>
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

#include <stdbool.h>

#define N 100
#define MAX 120000
#define ND 3
int dirs[ND][2] = { {-1, 0}, {-1, -1}, {-1, 1} };

bool used[N][N];

bool check_dir(int x, int y, int dx, int dy, int n) {
    int nx, ny;
    bool ret = true;

    for (;;) {
        nx = x + dx;
        ny = y + dy;

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
            break;
        }

        if (used[nx][ny]) {
            ret = false;
            break;
        }

        x = nx;
        y = ny;
    }

    return ret;
}

bool check(int x, int y, int n) {
    int i;
    bool ret = true;

    for (i = 0; i < ND; i++) {
        ret = check_dir(x, y, dirs[i][0], dirs[i][1], n);
        if (!ret) {
            return ret;
        }
    }
    return ret;
}

void dfs(int idx, int n, char ***res, int *sol_cnt) {
    int i, j;
    char **arr = NULL;

    if (idx >= n) {
        arr = (char **)malloc(n * sizeof(char *));
        for (i = 0; i < n; i++) {
            arr[i] = (char *)malloc((n + 1) * sizeof(char));
            for (j = 0; j < n; j++) {
                if (used[i][j] == 1) {
                    arr[i][j] = 'Q';
                } else {
                    arr[i][j] = '.';
                }
            }
            arr[i][j] = '\0';
        }
        res[*sol_cnt] = arr;
        (*sol_cnt) += 1;
        return;
    }

    for (i = 0; i < n; i++) {
        if (!check(idx, i, n)) {
            continue;
        }

        used[idx][i] = true;
        dfs(idx + 1, n, res, sol_cnt);
        used[idx][i] = false;
    }
}


char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    char ***res = NULL;
    int i, j, k;
    
    res = (char ***)malloc(MAX * sizeof(char **));
    (*returnColumnSizes) = malloc(MAX * sizeof(int));
    
    memset(used, 0, sizeof(used));
    *returnSize = 0;
    dfs(0, n, res, returnSize);

    *returnColumnSizes = malloc(*returnSize * sizeof(int));
    for (i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }

    return res;
}
/*最后的转换没写+有未知报错
void Save2Res(int n, int* tmp, char*** res){
    for (int i = 0; i < n; i++){
        printf("%d ", tmp[i]);
    }
    printf("\n");
}

void search(int n, int* returnSize, int cur, int* tmp, char*** res){
    if(cur == n){
        /*res[*returnSize] = (char **)malloc(sizeof(char *) * n);
        for (int i = 0; i < n; i++){
            res[*returnSize][i] = (char *)malloc(sizeof(char) * n);
        }*/
        Save2Res(n, tmp, res);
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
                search(n, returnSize, cur + 1, tmp, res);
            }
        }
    }
}

#define maxn 500
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    int *tmp;
    char ***res;
    tmp = (int *)malloc(sizeof(int) * n);
    res = (char ***)malloc(sizeof(char **) * maxn);
    *returnSize = 0;
    returnColumnSizes = (int **)malloc(sizeof(int *));
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * maxn);
    search(n, returnSize, 0, tmp, res);

    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++){
        returnColumnSizes[0][i] = n;
    }

    return res;
}

*/
// @lc code=end

