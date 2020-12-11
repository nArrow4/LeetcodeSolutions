/*
 * @lc app=leetcode.cn id=70 lang=c
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (48.13%)
 * Likes:    900
 * Dislikes: 0
 * Total Accepted:    161.3K
 * Total Submissions: 334.8K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 注意：给定 n 是一个正整数。
 * 
 * 示例 1：
 * 
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 * 
 * 示例 2：
 * 
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * 
 * 
 */

// @lc code=start

/**方法一：动态规划
 * 思路：
 * T:O(n)
 * S:O(n)
 */
int climbStairs(int n){
    int *dp;
    dp = (int *)malloc(sizeof(int) * (n+1));
    for (int i = 1; i <= n; i++){
        if(i == 1 || i == 2)
            dp[i] = i;
        else 
            dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

/*上述代码的空间优化
int climbStairs(int n){
    if ( n < 0 ) return 0;
    if (n <=2) return n;

    int fn1 = 1, fn2 = 2;
    int fn3;
    for (int i = 2 ;i < n; i++){
        fn3 = fn2 + fn1;
        fn1 = fn2;
        fn2 = fn3;
    }
    return fn3;
}
*/
/*递归
int _climb(int n, int *arr)
{
    if (arr[n] != 0 ) return arr[n];
    arr[n] = _climb(n-1, arr) + _climb(n-2, arr);
    return arr[n];
}

int climbStairs(int n){
    if ( n <  0 ) return 0;
    if ( n <= 2) return n;
    int *arr = (int*)calloc(n+1, sizeof(int));
    arr[1] = 1;
    arr[2] = 2;
    return _climb(n , arr);
}
*/
// @lc code=end

