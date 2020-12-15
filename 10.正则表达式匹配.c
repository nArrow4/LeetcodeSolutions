/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
/**方法一：直接解析正则表达式
 * 思路：还有点问题。放弃了，分支太多，或者是我考虑的太麻烦了。
 */

/**方法二：dp
 * 思路：考虑每次匹配s的第一个字符，
 *              1.如果下一位是*，则
 *                  1）继续用p[i]匹配
 *                  2）用p[i+2]匹配
 *              2.下一位不是*，就继续向后匹配
 * T:O(m+n)
 * S:O(1)
 */
bool isMatch(char * s, char * p){
    if(!*p) return !*s;
    bool flag = *s && ((*s == *p) || (*p == '.'));
    if(*(p+1) == '*'){
        return (flag && isMatch(s + 1, p)) || isMatch(s, p + 2);
    }
    return flag && isMatch(s + 1, p + 1);
}
// @lc code=end

