/*
 * @lc app=leetcode.cn id=69 lang=c
 *
 * [69] x 的平方根
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (37.63%)
 * Likes:    336
 * Dislikes: 0
 * Total Accepted:    109.6K
 * Total Submissions: 291.1K
 * Testcase Example:  '4'
 *
 * 实现 int sqrt(int x) 函数。
 * 
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 * 
 * 示例 1:
 * 
 * 输入: 4
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 8
 * 输出: 2
 * 说明: 8 的平方根是 2.82842..., 
 * 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 */

// @lc code=start


int mySqrt(int x){
    int left, right, mid;
    if(x == 0)
        return 0;
    if(x == 1)
        return 1;
    left = 1, right = x / 2;
    while(left < right){
        mid = (left + right + 1) / 2;
        if(mid == x/mid)
            return mid;
        if(mid < x/mid){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }
    return left;
}
/*二分法
注意：
mid > x/mid一定有mid*mid > x (比如3>(8/2))
mid*mid <= mid*(x/mid) < mid*(mid+1)
因为求的数是向下取整的，所以更新时尽量向下
如right = mid - 1。
*/
/*暴力搜索
注意在计算表达式的时候乘积可能越界（2^31）
int mySqrt(int x){
    long long int sqrt=0;
    for (; sqrt <= x; sqrt++){
        if( sqrt*sqrt<=x && (sqrt+1)*(sqrt+1)>x)
            return (int)sqrt;
    }
    return 0;
}
*/
// @lc code=end

