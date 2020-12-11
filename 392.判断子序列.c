/*
 * @lc app=leetcode.cn id=392 lang=c
 *
 * [392] 判断子序列
 *
 * https://leetcode-cn.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (48.53%)
 * Likes:    201
 * Dislikes: 0
 * Total Accepted:    45.1K
 * Total Submissions: 92.4K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 * 
 * 你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。
 * 
 * 
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 * 
 * 示例 1:
 * s = "abc", t = "ahbgdc"
 * 
 * 返回 true.
 * 
 * 示例 2:
 * s = "axc", t = "ahbgdc"
 * 
 * 返回 false.
 * 
 * 后续挑战 :
 * 
 * 如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T
 * 的子序列。在这种情况下，你会怎样改变代码？
 * 
 * 致谢:
 * 
 * 特别感谢 @pbrother 添加此问题并且创建所有测试用例。
 * 
 */

// @lc code=start
/**方法一：遍历
 * 思路：遍历s，每次取出一个字符在t中查找，记录找到的位置，下一次从此位置后一个开始找。
 * 70.02%
 * 100%
int find_char(char c, char* t, int pos){
    int len = strlen(t);
    for (int i = pos; i < len; i++){
        if(c == t[i]){
            return i;
        }
    }
    return -1;
}

bool isSubsequence(char * s, char * t){
    int len, pos = 0;
    len = strlen(s);
    for (int i = 0; i < len; i++){
        pos = find_char(s[i], t, pos);
        if(pos == -1){
            return false;
        }
        pos++;
    }
    return true;
}
*/
/**同方法一
 * 一个更简单的写法
 * 100%
 * 100%
 */
bool isSubsequence(char * s, char * t){
    while (*s) {
        if (!*t) {
            return false;
        }
        if (*s == *t) {
             ++s,++t;
        } else {
            ++t;
        }
    }
   return true;
}
// @lc code=end

