/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 */

// @lc code=start


char * longestCommonPrefix(char ** strs, int strsSize){
    int j=0;
    char *res;
    if(strsSize==1)
        return strs[0];
    for (int i = 0; i < strsSize && strs[i][j]; i++){
        if(strs[i][j]!=strs[i+1][j])
            break;
        if(i==strsSize-2){
            i = -1;
            j++;
        }
    }
    res = (char *)malloc(sizeof(char) * (j+1));
    for (int i = 0; i < j; i++){
        *(res + i) = strs[0][i];
    }
    *(res + j) = '\0';
    return res;
}
/*
所有的字母一样->两两相同，有不同的就break
*/

// @lc code=end

