/*
 * @lc app=leetcode.cn id=125 lang=c
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (42.97%)
 * Likes:    173
 * Dislikes: 0
 * Total Accepted:    91.1K
 * Total Submissions: 211.6K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */

// @lc code=start
bool isPalindrome(char * s){
    if(s == "") return true;
    int len = strlen(s), pos = -1;
    char *res;
    res = (char *)malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++){
        if(isupper(s[i]))
            res[++pos] = tolower(s[i]);
        else if(islower(s[i]) || isdigit(s[i]))
            res[++pos] = s[i];
    }
    pos++;
    for (int i = 0; i < pos/2; i++){
        if(res[pos - 1 - i] != res[i])
            return false;
    }
    return true;
}

// @lc code=end
