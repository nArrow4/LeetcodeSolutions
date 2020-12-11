/*
 * @lc app=leetcode.cn id=144 lang=c
 *
 * [144] 二叉树的前序遍历
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
思路：先储存当前节点，再遍历左子树和右子树
*/
// void preorder(struct TreeNode* root, int* res, int*resSize){
//     if(!root)
//         return;
//     res[*resSize] = root->val;
//     (*resSize)++;
//     preorder(root->left, res, resSize);
//     preorder(root->right, res, resSize);
// }

// int* preorderTraversal(struct TreeNode* root, int* returnSize){
//     int *res = (int *)malloc(sizeof(int) * 2000);
//     *returnSize = 0;
//     preorder(root, res, returnSize);
//     return res;
// }

/*
方法：迭代
思路：当前节点非空就入栈，向左继续遍历；当左儿子为空就取出栈顶，向右走一位，循环
*/
// int* preorderTraversal(struct TreeNode* root, int* returnSize){
//     int *res = (int *)malloc(sizeof(int) * 2000);
//     struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode*) * 2000);
//     int top = -1;
//     *returnSize = 0;
//     while(top > -1 || root){
//         //同一个节点不能两次进入这个循环
//         while(root){                         //当前节点不为空入栈
//             res[*returnSize] = root->val;
//             (*returnSize)++;
//             stack[++top] = root;
//             root = root->left;               //向右遍历
//         }
//         root = stack[top--];                 
//         root = root->right;                  //向左遇到空节点了向右走一步
//     }
//     return res;
// }

/*
方法：Morris遍历
思路：
*/
// int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//     int* res = malloc(sizeof(int) * 2000);
//     *returnSize = 0;
//     if (root == NULL) {
//         return res;
//     }

//     struct TreeNode *p1 = root, *p2 = NULL;

//     while (p1 != NULL) {
//         p2 = p1->left;
//         if (p2 != NULL) {
//             while (p2->right != NULL && p2->right != p1) {
//                 p2 = p2->right;
//             }
//             if (p2->right == NULL) {
//                 res[(*returnSize)++] = p1->val;
//                 p2->right = p1;
//                 p1 = p1->left;
//                 continue;
//             } else {
//                 p2->right = NULL;
//             }
//         } else {
//             res[(*returnSize)++] = p1->val;
//         }
//         p1 = p1->right;
//     }
//     return res;
// }


// @lc code=end

