/*
 * @lc app=leetcode.cn id=145 lang=c
 *
 * [145] 二叉树的后序遍历
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
思路：先遍历左子树和右子树，然后储存当前节点
*/
// void preorder(struct TreeNode* root, int* res, int*resSize){
//     if(!root)
//         return;
//     preorder(root->left, res, resSize);
//     preorder(root->right, res, resSize);
//     res[*resSize] = root->val;
//     (*resSize)++;
// }

// int* postorderTraversal(struct TreeNode* root, int* returnSize){
//     int *res = (int *)malloc(sizeof(int) * 2000);
//     *returnSize = 0;
//     preorder(root, res, returnSize);
//     return res;
// }

/*
方法：迭代
思路：关键思路就是怎么判断右子树遍历过了，以及已经遍历了右子树之后怎样跳过继续搜索左子树的过程
    需要再体会一下
*/
// int* postorderTraversal(struct TreeNode* root, int* returnSize){
//     int *res = (int *)malloc(sizeof(int) * 2000);
//     *returnSize = 0;
//     struct TreeNode **stack = (struct TreeNode *)malloc(sizeof(struct TreeNode) * 2000);
//     int top = -1;
//     struct TreeNode *pre = NULL;
//     while(top > -1 || root){
//         //一直向左走
//         while(root){
//             stack[++top] = root;
//             root = root->left;
//         }
//         root = stack[top--];        //取出元素一定要出栈
//         if(root->right == NULL || root->right == pre){       
//             //后一个条件表示右子树已经遍历过了
//             res[(*returnSize)++] = root->val;
//             pre = root;
//             root = NULL;            //为了跳过遍历左子树的过程
//         }
//         else{
//             //右子树没有遍历过
//             stack[++top] = root;
//             root = root->right;
//         }
//     }
//     return res;
// }
// @lc code=end

