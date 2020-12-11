/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.12%)
 * Likes:    1960
 * Dislikes: 0
 * Total Accepted:    225.2K
 * Total Submissions: 770.5K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start

/**方法一：DP
 * 
 * 
 * 
 */
#include<string.h>
char * longestPalindrome(char * s){
    int len = strlen(s);
    int dp[len][len];
    char *ans = (char *)malloc(sizeof(char) * (len + 1));
    strcpy(ans, "");
    memset(dp, 0, sizeof(int) * (len * len));
    for (int l = 0; l < len; l++){
        for (int i = 0; i < len - l;i++){
            int j = i + l;
            if(j >= len)
                break;
            if(l == 0){                 //子串长度为1
                dp[i][j] = 1;
            }
            else if(l == 1){            //子串长度为2
                dp[i][j] = (s[i] == s[j]);
            }
            else{                       //状态转移方程
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
            if(dp[i][j] && strlen(ans) < l + 1){    //记录最长子串
                strcpy(ans, s + i);
                ans[l + 1] = '\0';
            }
        }
    }
    return ans;
}


// @lc code=end

