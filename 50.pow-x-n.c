/*
 * @lc app=leetcode.cn id=50 lang=c
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (34.20%)
 * Likes:    287
 * Dislikes: 0
 * Total Accepted:    62.2K
 * Total Submissions: 181.6K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * 
 * 示例 1:
 * 
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2.10000, 3
 * 输出: 9.26100
 * 
 * 
 * 示例 3:
 * 
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 说明:
 * 
 * 
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 * 
 * 
 */

// @lc code=start
/**方法一：递归法
 * 思路：找到转移状态，分奇偶
 * 100%
 * 100%
double QuickMul(double x, int i){
    if(i == 0)
        return 1.0;
    double y;
    y = QuickMul(x, i / 2);
    return i % 2 ? y * y * x : y * y;
}

double myPow(double x, int n){
    long long m = n;
    return n > 0 ? QuickMul(x, m) : 1 / QuickMul(x, -m);
}
/**方法二：迭代法
 * 思路：对于x^n，可以分解成2^0+2^1+...（二进制的思想）。
 *      所以将x的幂转化为二进制，对应位为1就要平方。
 * 100%
 * 100%
 *
double QuickMul(double x, long long i){
    double ans = 1;
    double x_pow = x;
    while(i > 0){
        if(i%2 == 1){
            ans *= x_pow;
        }
        x_pow *= x_pow;
        i /= 2;
    }
    return ans;
}

double myPow(double x, int n){
    long long m = n;
    return n >= 0 ? QuickMul(x, m) : 1.0 / QuickMul(x, -m);
}
*/
// @lc code=end

