/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
/**方法一：直接解析正则表达式
 * 思路：还有点问题。放弃了，分支太多，或者是我考虑的太麻烦了。
 */

/**方法二：递归
 * 思路：考虑每次匹配s的第一个字符，
 *              1.如果下一位是*，则
 *                  1）继续用p[i]匹配
 *                  2）用p[i+2]匹配
 *              2.下一位不是*，就继续向后匹配
 * T:O(n^2)
 * S:O(1)
 *
bool isMatch(char * s, char * p){
    if(!*p) return !*s;
    bool flag = *s && ((*s == *p) || (*p == '.'));
    if(*(p+1) == '*'){
        return (flag && isMatch(s + 1, p)) || isMatch(s, p + 2);
    }
    return flag && isMatch(s + 1, p + 1);
}
*/
/**方法三：动态规划
 * 思路：
 * 
 * 
 * 
 */
#include<string.h>
bool isMatch(char * s, char * p){
    int m = strlen(s);
    int n = strlen(p);
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(int) * ((n + 1) * (m + 1)));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++){
        if(p[i - 1] == '*'){
            dp[0][i] = true;
        }
        else
            break;
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if(p[j - 1] == '.'){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] >= 'a' && p[j - 1] <= 'z'){
                dp[i][j] = (p[j - 1] == s[i - 1]) && dp[i - 1][j - 1];
            }
            else if(p[j - 1] == '*' && j > 1){
                dp[i][j] = dp[i - 1][j] | dp[i][j - 2];
            }
        }
    }
    return dp[m][n];
}
// @lc code=end

