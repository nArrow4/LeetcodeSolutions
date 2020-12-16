/*
 * @lc app=leetcode.cn id=44 lang=c
 *
 * [44] 通配符匹配
 *
 * https://leetcode-cn.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (27.13%)
 * Likes:    304
 * Dislikes: 0
 * Total Accepted:    25K
 * Total Submissions: 91.8K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
 * 
 * '?' 可以匹配任何单个字符。
 * '*' 可以匹配任意字符串（包括空字符串）。
 * 
 * 
 * 两个字符串完全匹配才算匹配成功。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "*"
 * 输出: true
 * 解释: '*' 可以匹配任意字符串。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "cb"
 * p = "?a"
 * 输出: false
 * 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "adceb"
 * p = "*a*b"
 * 输出: true
 * 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "acdcb"
 * p = "a*c?b"
 * 输入: false
 * 
 */

// @lc code=start

/**方法一：递归（暴力）
 * 思路：
 * T:TLE
 *
bool isMatch(char * s, char * p){
    if(!*p)
        return !*s;
    if(!*s){
        while(*p == '*')
            p++;
        return !*p;
    }
    bool first = *s && (*p == *s || *p == '?');
    if(*p == '*')
        return isMatch(s + 1, p) || isMatch(s, p + 1);
    return first && isMatch(s + 1, p + 1);
}*/
/**方法二：动态规划
 * 思路：dp[i][j]表示s[0 - i-1]与p[0 - j-1]能否匹配，根据p[j-1]分类讨论，
 *          1. p[j-1] == 'a'-'z'，只需判断p[j-1] == s[i-1]
 *          2. p[j-1] == '?'，直接匹配一位
 *          3. p[j-1] == '*',这个匹配是没有确定结果的，每次分匹配0个和匹配多个来讨论
 * T:O(n*m)
 * S:O(m*n)
 */
#include<string.h>
bool isMatch(char * s, char * p){
    int m = strlen(s);
    int n = strlen(p);
    int dp[m + 1][n + 1];               //dp[i][j] 表示s[1-i]与p[1-j]匹配
    memset(dp, 0, sizeof(int) * ((m+1) * (n+1)));
    dp[0][0] = true;
    for (int j = 1; j <= n; j++){
        if(p[j - 1]=='*')
            dp[0][j] = true;
        else
            break;
    }
    for (int i = 1; i <= m; i++){       // i for s
        for (int j = 1; j <= n; j++){   // j for p
            if(p[j - 1] == '?'){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if(p[j - 1] == '*'){
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
            }
            else{
                dp[i][j] = (s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
            }
        }
    }
    return dp[m][n];
}
// @lc code=end

