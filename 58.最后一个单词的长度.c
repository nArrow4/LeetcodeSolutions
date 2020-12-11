/*
 * @lc app=leetcode.cn id=58 lang=c
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.82%)
 * Likes:    183
 * Dislikes: 0
 * Total Accepted:    78.4K
 * Total Submissions: 238.7K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */

// @lc code=start


int lengthOfLastWord(char * s){
    int cnt = 0, flag = 0;
    for (char *p = s; *p; p++){
        if(*p == ' ' && *(p+1) != ' '){
            if(*(p+1) == '\0')
                return cnt;
            else
                cnt = 0;
        }
        else if(*p != ' ')
            cnt++;
    }
    return cnt;
}
/*
一开始没看懂题目WA了
题目要求的是最后一个单词（后面可以有空格）
*/
/*方法二.倒序查找
反向遍历，记录第一个不是空格开头的单词长度
int lengthOfLastWord(char * s){
    int length = 0;
    int cur = 0;
    bool IsBreak = false;
    
    for (cur = strlen(s) - 1; 0 <= cur; cur--)
    {
        if (cur[s] == ' ' && IsBreak == true)
        {
            break;
        }

        if (cur[s] != ' ')
        {
            length++;
            IsBreak = true;
        }
    }

    return length;
}
*/

// @lc code=end

