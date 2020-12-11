/*
 * @lc app=leetcode.cn id=96 lang=c
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start

/**方法一：dp
 * 
 * 
 */
int numTrees(int n){
    
}

/**方法二：数学方法
 * 
 * T:O(n) 
 * S:O(1)
int numTrees(int n) {
    long long C = 1;
    for (int i = 0; i < n; ++i) {
        C = C * 2 * (2 * i + 1) / (i + 2);
    }
    return (int)C;
}
*/
// @lc code=end

