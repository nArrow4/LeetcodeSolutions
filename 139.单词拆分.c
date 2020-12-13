/*
 * @lc app=leetcode.cn id=139 lang=c
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <string.h>

int check(char *s, char ** wordDcit, int wordDictSize, int i, int j){
    char *tmp = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    tmp = s + j + 1;
    tmp[i - j] = '\0';      //j+1 to i
    // for (int k = 0; k < wordDictSize; k++){
    //     if(strcmp(tmp, wordDcit[k]) == 1){
    //         free(tmp);
    //         return true;
    //     }
    // }
    return false;
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int len = strlen(s);
    bool dp[len + 1];
    memset(dp, 0, sizeof(bool) * (len + 1));
    dp[0] = true;
    for (int i = 1; i <= len; i++){     //for 1 to len
        for (int j = 0; j < i; j++){    //for 0 to i-1
            printf("%d ", dp[j]);
            //s:j+1 to i -> 1 to 
            if(check(s, wordDict, wordDictSize, i, j) && dp[j]){  
                dp[i] = true; 
                break;
            }
        }
        printf("%d ", dp[i]);
    }
    return dp[len];
}
// @lc code=end

