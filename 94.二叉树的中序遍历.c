/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
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
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
方法：递归
思路：先遍历左子树，储存当前节点，然后遍历右子树
*/
// void preorder(struct TreeNode* root, int* res, int*resSize){
//     if(!root)
//         return;
//     preorder(root->left, res, resSize);
//     res[*resSize] = root->val;
//     (*resSize)++;
//     preorder(root->right, res, resSize);
// }

// int* inorderTraversal(struct TreeNode* root, int* returnSize){
//     int *res = (int *)malloc(sizeof(int) * 2000);
//     *returnSize = 0;
//     preorder(root, res, returnSize);
//     return res;
// }

/*
方法：迭代
思路：先一直向左走，左儿子为空就保存当前节点，向右走一步
*/
// int* inorderTraversal(struct TreeNode* root, int* returnSize){
//     int *res = (int *)malloc(sizeof(int) * 2000);
//     *returnSize = 0;
//     struct TreeNode **stack = (struct TreeNode *)malloc(sizeof(struct TreeNode) * 2000);
//     int top = -1;
//     while(top > -1 || root){
//         while(root){
//             stack[++top] = root;
//             root = root->left;
//         }
//         res[(*returnSize)++] = stack[top]->val;//左儿子为空，入栈，往右走一步
//         root = stack[top--]->right;
//     }
//     return res;
// }
// @lc code=end

