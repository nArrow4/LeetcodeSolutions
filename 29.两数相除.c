/*
 * @lc app=leetcode.cn id=29 lang=c
 *
 * [29] 两数相除
 *
 * https://leetcode-cn.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (19.39%)
 * Likes:    303
 * Dislikes: 0
 * Total Accepted:    40.5K
 * Total Submissions: 208.7K
 * Testcase Example:  '10\n3'
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 
 * 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) =
 * -2
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 * 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
 * 
 * 示例 2:
 * 
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 * 解释: 7/-3 = truncate(-2.33333..) = -2
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 * 
 * 
 */

// @lc code=start
/**方法一：逐项减
 * 
 * 结果是对的，但是会超时！
 * 
#define INT_MAX 0X7FFFFFFF
#define INT_MIN 0X80000000

int divide(int dividend, int divisor){
    if(dividend == 0)   // 特殊情况判断
		return 0;
    else if(dividend == INT_MIN && divisor == -1)   // 被除数为INT_MIN的两种特殊情况
		return INT_MAX;
    else if(dividend == INT_MIN && divisor == 1)
		return INT_MIN;
    else if(dividend == INT_MIN && divisor == INT_MIN)  // 除数为INT_MIN，就这两种情况
        return 1;
    else if(divisor == INT_MIN)
        return 0;
    int flag = 1, cnt = 0;
    if((dividend < 0)^(divisor < 0)){
        flag = -1;
    }
    divisor = abs(divisor);
    if(dividend == INT_MIN){
        dividend += divisor;
        cnt++;
    }
    dividend = abs(dividend);
    while(dividend > 0){
        dividend -= divisor;
        cnt++;
    }
    if(dividend == 0){
        if(flag == -1)
            return -cnt;
        else
            return cnt;
    }
    if(flag == -1)
        return -cnt+1;
    else
        return cnt-1;
}
*/
/**方法二：位运算法
 * 思路：这个方法太妙了！！！
 * 61%
 * 100%
 */
#define INT_MAX 0X7FFFFFFF
#define INT_MIN 0X80000000

int divide(int dividend, int divisor)
{
    int result = 0;     // 存放结果值
    if(dividend == 0)   // 特殊情况判断
		return 0;
    else if(dividend == INT_MIN && divisor == -1)   // 被除数为INT_MIN的两种特殊情况
		return INT_MAX;
    else if(dividend == INT_MIN && divisor == 1)
		return INT_MIN;
    else if(dividend == INT_MIN && divisor == INT_MIN)  // 除数为INT_MIN，就这两种情况
        return 1;
    else if(divisor == INT_MIN)
        return 0;

    bool negative = (dividend ^ divisor) < 0;       // 判断结果是否为负数 

    // 若被除数为INT_MIN，先减一次，在再进行运算，不然取abs会溢出
    if(dividend == INT_MIN)
    {
        dividend += abs(divisor);
        result++;
    }
    int t = abs(dividend);
    int d = abs(divisor);

    //每个数都可以写成i1*2^0+i2*2^1+...，我们只需要把幂的系数固定成d就行
    for(int i = 31; i >= 0; i--)
    {
        if((t >> i) >= d)
        {
            result += 1 << i;
            t -= d << i;
        }
    }

    if(result == INT_MIN)
        return INT_MAX;
    else
        return negative ? -result : result;
    return 0;
}

// @lc code=end

