/*
 * @lc app=leetcode.cn id=111 lang=c
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (41.84%)
 * Likes:    236
 * Dislikes: 0
 * Total Accepted:    62.8K
 * Total Submissions: 150K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
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
#define min(a, b) (a>b?b:a)
int minDepth(struct TreeNode* root){
    if(!root)
        return 0;
    int left, right;
    left = minDepth(root->left)+1;
    right = minDepth(root->right)+1;
    if(!root->left)
        return right;
    if(!root->right)
        return left;
    return min(left, right);
}*/
/*dfs
和最大深度那题差不多
最小深度是指根节点到叶节点的最短长度
*/
/*bfs
注意理解最小深度的意思
int minDepth(struct TreeNode* root){
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return 1;
    int layer = 1, front = -1, rear = -1, step;
    struct TreeNode *queue[10000], *cur;
    cur = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    queue[++rear] = root;
    while(front < rear){
        step = rear - front;
        for (int i = 0; i < step; i++){
            cur = queue[++front];
            if(!cur->left && !cur->right)
                return layer;
            if(cur->left){
                queue[++rear] = cur->left;
            }
            if(cur->right){
                queue[++rear] = cur->right;
            }
        }
        layer++;
    }
    return layer;
}
*/
// @lc code=end
