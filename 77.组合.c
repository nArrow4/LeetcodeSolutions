/*
 * @lc app=leetcode.cn id=77 lang=c
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (73.34%)
 * Likes:    238
 * Dislikes: 0
 * Total Accepted:    42.7K
 * Total Submissions: 58.1K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define maxn 10000
void permutation(int n, int k, int* returnSize, int** returnColumnSizes, int** res, int pos, int val){
    if(pos == k){
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
        res[*returnSize] = (int *)malloc(sizeof(int) * (k+1));
        //这一行很关键，以n=4,k=2为例
        //res[*returnSize][pos] = i;这行代码将以1开头的第一个数组储存完之后
        //回溯储存第二个，这时pos以前的数没有储存在新的res[*returnSize]里面
        memcpy(res[*returnSize], res[*returnSize - 1], sizeof(int) * (k + 1));
    }
    else{
        for (int i = val + 1; i <= n; i++){
            res[*returnSize][pos] = i;
            permutation(n, k, returnSize, returnColumnSizes, res, pos + 1, i);
        }
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int **res;
    res = (int **)malloc(sizeof(int *) * maxn);
    memset(res, 0, sizeof(int **) * maxn);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * maxn);
    res[*returnSize] = (int *)malloc(sizeof(int) * (k+1));
    permutation(n, k, returnSize, returnColumnSizes, res, 0, 0);
    return res;
}

/*
//求组合的数量， 可以优化maxn
int getMaxComBineNum(int n, int k){
    int         iRet        = 0;
    int         i           = 0;
    long int    iTmp1       = 1;
    long int    iTmp2       = 1;

    for (i = 0; i < k; i++)
    {
        iTmp1 *= n - i;
        iTmp2 *= i + 1;
    }
    iRet = iTmp1 / iTmp2 + 1;
    return iRet;
}
*/
// @lc code=end

