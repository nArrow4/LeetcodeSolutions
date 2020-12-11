/*
 * @lc app=leetcode.cn id=102 lang=c
 *
 * [102] 二叉树的层序遍历
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

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **res;
    int base = 0, head = 0, len, tempHead;
    *returnSize = 0;
    if(root == NULL)
        return NULL;
    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 10000);
    res = (int **)malloc(sizeof(int *) * 10000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 10000);
    queue[head++] = root;
    while(head != base){
        len = head - base;
        tempHead = head;
        res[(*returnSize)] = (int *)malloc(sizeof(int) * len);
        for (int i = base; i < head; i++){
            //下一层的节点入队
            if(queue[i]->left)
                queue[tempHead++] = queue[i]->left;
            if(queue[i]->right)
                queue[tempHead++] = queue[i]->right;
            //存储当前层的节点
            res[(*returnSize)][i - base] = queue[i]->val;
        }
        returnColumnSizes[0][(*returnSize)++] = len;
        base += len;
        head = tempHead;
    }
    return res;
}

// @lc code=end

