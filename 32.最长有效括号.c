/*
 * @lc app=leetcode.cn id=32 lang=c
 *
 * [32] 最长有效括号
 */

// @lc code=start

/**方法一：dp
 * 思路：dp[i]为以i结尾的最长有效括号的长度。
 *          1.如果s[i]为‘（’，显然dp[i]为0
 *          2.如果s[i]为‘）’，
 *              1）如果s[i-1] == ‘（’，dp[i] = dp[i-2] + 2;
 *              2）如果s[i-1] == ‘）’ && s[i-dp[i-1]-1] == ‘（’，dp[i] = 
 *                      dp[i-1] 以i-1结尾的最长有效括号长度
 *                     +dp[i-dp[i-1]-2] 把s[i]匹配的‘（’前的有效括号连接起来
 *                     +2 s[i]和匹配到的‘（’
 * T:O(n)
 * S:O(n)
 *
#define max(a, b) (a>b?a:b)
#include<string.h>
int longestValidParentheses(char * s){
    int len = strlen(s), max = 0;
    if(len == 0)
        return 0;
    int dp[len];
    memset(dp, 0, sizeof(int) * (len));
    for (int i = 1; i < len; i++){
        if(s[i] == ')'){
            if(s[i-1] == '('){
                dp[i] = dp[max(i - 2, 0)] + 2;
            }
            else if(i - dp[i - 1] > 0 && s[i-dp[i-1]-1] == '('){
                dp[i] = dp[i - 1] + dp[max(i - dp[i - 1] - 2, 0)] + 2;
            }
        }
        max = max(max, dp[i]);
    }
    return max;
}
*/
/**方法二：栈
 * 
 * 
 * 
 */
int longestValidParentheses(char * s){

}
// @lc code=end

