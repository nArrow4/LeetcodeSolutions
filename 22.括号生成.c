/*
 * @lc app=leetcode.cn id=22 lang=c
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (73.71%)
 * Likes:    837
 * Dislikes: 0
 * Total Accepted:    93.7K
 * Total Submissions: 127K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backTracking(int n, int* returnSize, char** res, int left, int right, int pos){
    if(left == n && right == n){
        res[*returnSize][pos] = '\0';
        (*returnSize)++;
        res[*returnSize] = (char *)malloc(sizeof(char) * (2 * n + 1));
        memcpy(res[*returnSize], res[*returnSize - 1], sizeof(char) * (2 * n + 1));
    }
    else{
        if(left < n){
            res[*returnSize][pos] = '(';
            backTracking(n, returnSize, res, left + 1, right, pos + 1);
        }
        if(left > right){
            res[*returnSize][pos] = ')';
            backTracking(n, returnSize, res, left, right + 1, pos + 1);
        }
    }
}
#define  maxn 5000
char ** generateParenthesis(int n, int* returnSize){
    char **res;
    res = (char **)malloc(sizeof(char *) * maxn);
    *returnSize = 0;
    res[*returnSize] = (char *)malloc(sizeof(char) * (2 * n + 1));
    backTracking(n, returnSize, res, 0, 0, 0);

    return res;
}


// @lc code=end

