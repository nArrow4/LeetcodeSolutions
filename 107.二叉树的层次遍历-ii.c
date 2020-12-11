/*
 * @lc app=leetcode.cn id=107 lang=c
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (64.66%)
 * Likes:    211
 * Dislikes: 0
 * Total Accepted:    49.2K
 * Total Submissions: 76.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
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
/*
方法：队列
思路：先用队列顺序储存，再反向取出
*/
// int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
//     int **res;
//     int base = 0, head = 0, tempHead, level = 0;
//     int len[100];
//     *returnSize = 0;
//     if(!root)
//         return NULL;
//     struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 10000);
//     res = (int **)malloc(sizeof(int *) * 10000);
//     *returnColumnSizes = (int *)malloc(sizeof(int) * 10000);
//     queue[head++] = root;           //head指向下一位
//     while(head != base){            //将整个树一层一层入队
//         len[level] = head - base;   //len为当前层节点的数量
//         tempHead = head;
//         for (int i = base; i < head; i++){
//             //下一层的节点入队
//             if(queue[i]->left)
//                 queue[tempHead++] = queue[i]->left;
//             if(queue[i]->right)
//                 queue[tempHead++] = queue[i]->right;
//         }
//         base += len[level++];       //level-1储存最后一层
//         head = tempHead;            //tempHead-1储存最后一位
//     }
//     head--;
//     //从底层向顶层取出
//     for (int i = level - 1; i >= 0; i--){
//         returnColumnSizes[0][(*returnSize)] = len[i];
//         res[(*returnSize)] = (int *)malloc(sizeof(int) * (len[i] + 1));
//         base = head - len[i] + 1;
//         //从base到head储存,两边都取到
//         for (int j = base; j <= head; j++){
//             res[(*returnSize)][j - base] = queue[j]->val;
//         }
//         head = base - 1;
//         (*returnSize)++;
//     }
//     return res;
// }

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **res;
    int base = 0, head = 0, len, tempHead;
    *returnSize = 0;
    if(root == NULL)
        return NULL;
    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 10000);
    res = (int **)malloc(sizeof(int *) * 10000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 10000);
    queue[head++] = root;
    while(head != base){                                        //自顶向下取出
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
    for (int i = 0; 2 * i < *returnSize; i++){                  //反转
        int *tmp1 = res[*returnSize - i - 1];
        res[*returnSize - i - 1] = res[i];
        res[i] = tmp1;
        tmp1 = returnColumnSizes[0][*returnSize - i - 1];
        returnColumnSizes[0][*returnSize - i - 1] = returnColumnSizes[0][i];
        returnColumnSizes[0][i] = tmp1;
    }
    return res;
}
// @lc code=end