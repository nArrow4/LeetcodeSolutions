/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (50.59%)
 * Likes:    690
 * Dislikes: 0
 * Total Accepted:    115.5K
 * Total Submissions: 228.3K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
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

bool Symmetric(struct TreeNode* left_r, struct TreeNode* right_r){
    if(left_r == NULL && right_r == NULL)
        return true;
    if(left_r == NULL || right_r == NULL)
        return false;
    if(left_r->val == right_r->val){
        return Symmetric(left_r->left, right_r->right) && Symmetric(left_r->right, right_r->left);
    }
    else
        return false;
}

bool isSymmetric(struct TreeNode* root){
    if(root != NULL){
        return Symmetric(root->left, root->right);
    }
    else
        return true;
    return true;
}

/*
分别判断左支的左子树，和右支的右子树相等
左支的右子树和右支的左子树相等
也可以仿照上一题写，递归的时候把左右子支的位置换一下
*/
/*用队列，递推写法dfs
两个队列代表两个树
父节点相等，就把两个子节点入队
并继续向下搜索
#define QUEUESIZE 200
bool isSymmetric(struct TreeNode* root){
    if( !root ) return true;
    if( !root->left && !root->right ) return true;
    if( !root->left || !root->right ) return false;

    struct TreeNode *left_r[QUEUESIZE];
    struct TreeNode *right_r[QUEUESIZE];
    struct TreeNode *r, *l;
    int rear1, rear2, front1, front2;
    rear1 = rear2 = front1 = fornt2 = -1;
    left_r[++rear1] = root->left;
    right_r[++rear2] = root->right;
    while(rear1 > front1){
        l = left_r[++front1];
        r = right_r[++front2];

        if(!l && !r) continue;
        if(!l || !r) return false;
        if(l->val != r->val) return false;
        //当l和r的值相等的时候，把子支存到队列里
        left_r[++rear1] = l->left;
        right_r[++rear2] = r->right;
        left_r[++rear1] = l->right;
        right_r[++rear2] = r->left;
    }
}
*/
// @lc code=end
