/*
 * @lc app=leetcode.cn id=103 lang=c
 *
 * [103] 二叉树的锯齿形层次遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define N 2000
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    // int **res = (int **)malloc(sizeof(int *) * N);
    // struct TreeNode* queue[N];
    // int front = 0, rear = 0, len, index;
    // res[0] = (int *)malloc(sizeof(int) * 1);
    // res[0][0] = root->val;
    // queue[rear++] = root;
    // *returnSize = 1;
    // while(front < rear){
    //     len = rear - front;
    //     for (int i = 0; i < len; i++){
    //         index = front + i;
    //     }
    // }
}


// @lc code=end

