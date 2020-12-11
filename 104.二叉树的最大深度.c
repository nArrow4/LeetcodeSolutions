/*
 * @lc app=leetcode.cn id=104 lang=c
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (72.62%)
 * Likes:    490
 * Dislikes: 0
 * Total Accepted:    149.3K
 * Total Submissions: 205.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
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
/*
方法：递归
思路：左右子树中最长的加1就是当前节点的最大深度
*/
// #define max(a, b) (a>b?a:b)
// int maxDepth(struct TreeNode* root){
//     if(!root)
//         return 0;
//     int left, right;
//     left = maxDepth(root->left);
//     right = maxDepth(root->right);
//     return max(left, right) + 1;        //左右子树中最长的加1就是当前节点的最大深度

//     return 0;
// }
/*
方法：bfs
思路：层序遍历，每遍历一层，深度加1
*/
// int maxDepth(struct TreeNode *root){
//     int depth = 0, base = 0, top = 0;
//     if(!root)
//         return 0;
//     struct TreeNode **queue = malloc(sizeof(struct TreeNode *) * 10000);
//     queue[top++] = root;
//     while(base < top){
//         int tempTop = top;
//         for (int i = base; i < tempTop; i++, base++){
            
//             if(queue[i]->left)
//                 queue[top++] = queue[i]->left;
//             if(queue[i]->right)
//                 queue[top++] = queue[i]->right;
            
//         }
//         depth++;
//     }
//     return depth;
// }

/*
方法：递归
思路：每次dfs，每次向下一层current就加一，找到根节点后跟当前最大深度比较，如果更大就更新
*/
// void dfs(struct TreeNode* node, int current, int* ret)
// {
//     if(node == NULL)
//     {
//         *ret = current > *ret ? current : *ret;
//     }
//     else
//     {
//         current++;

//         dfs(node->left, current, ret);
//         dfs(node->right, current, ret);
//     }
// }

// int maxDepth(struct TreeNode* root){
//     int ret = 0;

//     if(root != NULL)
//     {
//         dfs(root,0,&ret);
//     }

//     return ret;
// }
// @lc code=end

