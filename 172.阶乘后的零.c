/*
 * @lc app=leetcode.cn id=172 lang=c
 *
 * [172] 阶乘后的零
 *
 * https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (39.86%)
 * Likes:    258
 * Dislikes: 0
 * Total Accepted:    33K
 * Total Submissions: 82.7K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，返回 n! 结果尾数中零的数量。
 * 
 * 示例 1:
 * 
 * 输入: 3
 * 输出: 0
 * 解释: 3! = 6, 尾数中没有零。
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: 1
 * 解释: 5! = 120, 尾数中有 1 个零.
 * 
 * 说明: 你算法的时间复杂度应为 O(log n) 。
 * 
 */

// @lc code=start
int trailingZeroes(int n){
    int res = 0;

    // 5 的个数就是 n / 5 + n / 25 + n / 125 ...
    while (0 < n)
    {
        res += n / 5;
        n /= 5;
    }

    return res;
}
/*
int Cal(int n, int m){
    int cnt = 0;
    while(n){
        if((int)(n*1.0/m) == n/m){
            cnt++;
        }
        else
            break;
    }
    return cnt;
}

#define min(a, b) (a>b?b:a)

int trailingZeroes(int n){
    int cnt5, cnt2, cnt0, cnt = 0;
    for (int i = 1; i <= n; i++){
        cnt5 = Cal(i, 5);
        cnt += cnt5;
    }
    return cnt;
}
*/

// @lc code=end

