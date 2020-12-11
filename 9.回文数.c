/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start


bool isPalindrome(int x){
    if(x<0)
        return false;
    int tmp=x;
    long long int res = 0;
    while(tmp!=0){
        res = res * 10 + tmp % 10;
        tmp /= 10;
    }
    if(res == x)
        return true;
    else
        return false;
    return true;
}
/*
跟整数翻转有点类似
负数直接false
整数就先翻转，然后看是不是相等
*/

// @lc code=end

