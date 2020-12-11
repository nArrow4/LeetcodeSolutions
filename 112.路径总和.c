/*
 * @lc app=leetcode.cn id=112 lang=c
 *
 * [112] 路径总和
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
方法：深度优先搜索（效率有点低）
思路：每次找到叶子结点然后判断当前值是否等于sum。
注意：递归时，可以在传参的时候增加变量值，达到传递状态、回溯时撤回状态的目的。
*/
void dfs(struct TreeNode* root, int sum, int cur, int *flag){
    if(!root)
        return;
    if(cur+root->val == sum && !root->left && !root->right){
        //不能只用root非空判断叶子结点
        *flag = 1;
        return;
    }
    dfs(root->left, sum, cur+root->val, flag);
    dfs(root->right, sum, cur+root->val, flag);
}

bool hasPathSum(struct TreeNode* root, int sum){
    if(!root)
        return false;
    int cur = 0, flag = 0;
    if(!root->left && !root->right)
        return root->val == sum;
    if(!root->left) dfs(root->right, sum, cur+root->val, &flag);
    else if(!root->right) dfs(root->left, sum, cur+root->val, &flag);
    else dfs(root, sum, cur, &flag);
    if(flag == 1)
        return true;
    return false;
}


// @lc code=end

