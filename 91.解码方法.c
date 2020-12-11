/*
 * @lc app=leetcode.cn id=91 lang=c
 *
 * [91] 解码方法
 */

// @lc code=start

/**方法一：dp
 * 思路：dp[i]记录以i结尾的编码串解码方法种数。
 *          1.如果第i位和第i-1位不能组成合适的编码，则
 *              dp[i] = dp[i-1]
 *          2.如果第i位和第i-1位可以组成合适的编码，则
 *              dp[i] = dp[i-1] + dp[i-2]
 * 特别注意：可能包含多余的0
 * T:O(n)
 * S:O(n)
 */
#include<string.h>
int numDecodings(char * s){
    int len = strlen(s);
    int dp[len];
    memset(dp, 0, sizeof(int) * len);
    for (int i = 0; i < len; i++){
        if(i == 0){
            if(s[i] == '0')
                return 0;
            else 
                dp[i] = 1;
        }
        else{
            if(s[i] == '0' && s[i-1] != '1' && s[i-1] != '2'){
                return 0;
            }
            else if((s[i-1] == '1' && s[i] >= '0' && s[i] <= '9' ) || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6') ){
                if(i == 1){
                    dp[i] = s[i] == '0' ? 1 : 2;
                }
                else{
                    dp[i] = s[i] == '0' ? dp[i - 2] : dp[i - 2] + dp[i - 1];
                }
            }
            else
                dp[i] = dp[i - 1];
        }
    }
    return dp[len - 1];
}
// @lc code=end

