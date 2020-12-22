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

/**方法一：bfs
 * 思路：用一个队列
 * T:O(N)
 * S:O(N)
 */
#define N 2000
#define L 1
#define R 0
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * N);
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * N);
    returnColumnSizes[0][0] = 1;
    struct TreeNode* queue[N];
    int front = 0, rear = 0, len, level = 0;
    // res[0] = (int *)malloc(sizeof(int) * 1);
    // res[0][0] = root->val;
    queue[rear++] = root;
    while(front < rear){    // 包括front,不包括rear
        len = rear - front;
        level++;
        returnColumnSizes[0][level - 1] = len;
        res[level - 1] = (int *)malloc(sizeof(int) * len);
        for (int i = front + 0; i < front + len; i++){
            if(queue[i]->left){
                queue[rear++] = queue[i]->left;
            }
            if(queue[i]->right){
                queue[rear++] = queue[i]->right;
            }
        }
        // printf("%d %d ", front, rear);
        if(level % 2 == L){         //从左开始
            for (int i = 0; i < len; i++)
                res[level - 1][i] = queue[front + i]->val;
        }
        else if(level % 2 == R){    //从右开始
            for (int i = 0; i < len; i++)
                res[level - 1][len - 1 - i] = queue[front + i]->val;
        }
        front += len;
    }
    *returnSize = level;
    return res;
}


// @lc code=end

